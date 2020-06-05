#include "web/file_handler.h"

using namespace Pistache;

FileHandler::FileHandler(std::filesystem::path prefix, std::vector<std::string> resources)
    : _prefix{prefix},
      _resources{resources}
{
}

void FileHandler::onRequest(const Http::Request &request, Http::ResponseWriter response)
{
    if (request.method() != Http::Method::Get)
    {
        response.send(Http::Code::Method_Not_Allowed);
        return;
    }

    if (request.resource() == "/")
    {
        Http::serveFile(response, _prefix / "index.html");
        return;
    }

    auto const resource = std::find(_resources.begin(), _resources.end(), request.resource().substr(1));
    if (resource != _resources.end())
    {
        Http::serveFile(response, _prefix / *resource);
        return;
    }

    response.send(Http::Code::Not_Found);
}
