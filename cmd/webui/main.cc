#include "machine/machine.h"
#include "machine/machine_api.h"
#include "rest/rest_server.h"
#include "web/frontend.h"

#include <csignal>
#include <filesystem>
#include <optional>
#include <thread>

namespace {
std::function<void()> signal_handler;
} // namespace

struct Arguments {
  std::optional<std::filesystem::path> ui_folder;
  std::optional<std::string> api_url;
};

Arguments parse(int argc, char *argv[]) {
  Arguments args{};
  auto pos = 1;
  while (pos < argc) {
    using namespace std::string_literals;

    if (argv[pos] == "--ui"s) {
      ++pos;
      if (pos < argc) {
        args.ui_folder = argv[pos];
      }
    } else if (argv[pos] == "--url"s) {
      ++pos;
      if (pos < argc) {
        args.api_url = argv[pos];
      }
    }
    ++pos;
  }
  return args;
}

int main(int argc, char *argv[]) {
  auto const args = parse(argc, argv);

  auto const api =
      std::make_shared<MachineApi>(std::make_shared<Machine>(), args.api_url);
  auto const rest = std::make_shared<RestServer>(api);
  auto const ui = std::make_shared<Frontend>(args.ui_folder);

  std::thread rest_thread{[&] { rest->start(); }};
  std::thread ui_thread{[&] { ui->start(); }};

  signal_handler = [&] {
    ui->shutdown();
    rest->shutdown();
  };
  std::signal(SIGINT, [](int) { signal_handler(); });
  std::signal(SIGTERM, [](int) { signal_handler(); });

  rest_thread.join();
  ui_thread.join();
}
