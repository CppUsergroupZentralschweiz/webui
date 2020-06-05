#include "rest/rest_server.h"

#include "machine/machine_api.h"

using namespace Pistache;

RestServer::RestServer(std::shared_ptr<MachineApi> api)
    : _api{api},
      _endpoint{Address{Ipv4::any(), Port}},
      _router{}
{
}

void RestServer::start()
{
    auto const options = Http::Endpoint::options()
                             .threads(Threads)
                             .flags(Tcp::Options::ReuseAddr);

    _endpoint.init(options);

    Rest::Routes::Get(_router, "/machine/state", Rest::Routes::bind(&MachineApi::get_state, _api));
    Rest::Routes::Post(_router, "/machine/start", Rest::Routes::bind(&MachineApi::do_start, _api));

    _endpoint.setHandler(_router.handler());
    _endpoint.serve();
}

void RestServer::shutdown()
{
    _endpoint.shutdown();
}