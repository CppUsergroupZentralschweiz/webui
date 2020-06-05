#include "web/frontend.h"

#include "web/file_handler.h"

using namespace Pistache;

namespace
{
std::vector<std::string> list_resources(std::optional<std::filesystem::path> ui_folder)
{
    if (not ui_folder)
    {
        return {};
    }
    auto const prefix = ui_folder.value();

    std::vector<std::string> resources{};
    for (auto &entry : std::filesystem::recursive_directory_iterator(prefix))
    {
        if (entry.is_regular_file())
        {
            auto const resource = entry.path().lexically_relative(prefix).generic_string();
            resources.push_back(resource);
        }
    }
    return resources;
}
} // namespace

Frontend::Frontend(std::optional<std::filesystem::path> ui_folder)
    : _ui_folder{ui_folder.value_or("./ui")},
      _endpoint{Address{Ipv4::any(), Port}}
{
}

void Frontend::start()
{
    auto const options = Http::Endpoint::options()
                             .threads(Threads)
                             .flags(Tcp::Options::ReuseAddr);

    _endpoint.init(options);

    auto const resources = list_resources(_ui_folder);
    _endpoint.setHandler(Http::make_handler<FileHandler>(_ui_folder, resources));
    _endpoint.serve();
}

void Frontend::shutdown()
{
    _endpoint.shutdown();
}
