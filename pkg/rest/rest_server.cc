#include "rest/rest_server.h"

#include "machine/machine_api.h"

using namespace Pistache;

RestServer::RestServer(std::shared_ptr<MachineApi> api)
    : _api{api}, _endpoint{Address{Ipv4::any(), Port}}, _router{} {}

void RestServer::start() {
  auto const options =
      Http::Endpoint::options().threads(Threads).flags(Tcp::Options::ReuseAddr);

  _endpoint.init(options);

  Rest::Routes::Get(_router, "/machine/state",
                    Rest::Routes::bind(&MachineApi::get_state, _api));
  Rest::Routes::Post(_router, "/machine/start",
                     Rest::Routes::bind(&MachineApi::do_start, _api));

  // Exercise 2
  // Add route for /machine/stop -> do_stop.
  Rest::Routes::Post(_router, "/machine/stop",
                     Rest::Routes::bind(&MachineApi::do_stop, _api));

  // Exercise 3
  // Add route for /machine/temperature -> get_temperature.
  Rest::Routes::Get(_router, "/machine/temperature",
                    Rest::Routes::bind(&MachineApi::get_temperature, _api));

  _endpoint.setHandler(_router.handler());
  _endpoint.serve();
}

void RestServer::shutdown() { _endpoint.shutdown(); }
