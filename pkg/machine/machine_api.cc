#include "machine/machine_api.h"

#include "machine/machine.h"

using namespace Pistache;

MachineApi::MachineApi(std::shared_ptr<Machine> machine)
    : _machine{machine}
{
}

void MachineApi::get_state(const Rest::Request &request, Http::ResponseWriter response)
{
    auto const state = _machine->state();

    response.headers().add<Http::Header::AccessControlAllowOrigin>("*"); // CORS
    response.send(Http::Code::Ok, state.dump());
}

void MachineApi::get_temperature(const Rest::Request &request, Http::ResponseWriter response)
{
    response.headers().add<Http::Header::AccessControlAllowOrigin>("*"); // CORS
    response.send(Http::Code::Not_Implemented);
}

void MachineApi::do_start(const Rest::Request &request, Http::ResponseWriter response)
{
    response.headers().add<Http::Header::AccessControlAllowOrigin>("*"); // CORS
    response.send(Http::Code::Not_Implemented);
}

void MachineApi::do_stop(const Rest::Request &request, Http::ResponseWriter response)
{
    response.headers().add<Http::Header::AccessControlAllowOrigin>("*"); // CORS
    response.send(Http::Code::Not_Implemented);
}
