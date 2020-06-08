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
    // Exercise 3
    // Return the current temperature.

    response.headers().add<Http::Header::AccessControlAllowOrigin>("*"); // CORS
    response.send(Http::Code::Not_Implemented);
}

void MachineApi::do_start(const Rest::Request &request, Http::ResponseWriter response)
{
    // Exercise 1
    // Start the machine.
    // Return Http::Code::Not_Modified if the machine is already running.

    response.headers().add<Http::Header::AccessControlAllowOrigin>("*"); // CORS
    response.send(Http::Code::Not_Implemented);
}

void MachineApi::do_stop(const Rest::Request &request, Http::ResponseWriter response)
{
    // Exercise 2
    // Stop the machine.
    // Return Http::Code::Not_Modified if the machine is not running.

    response.headers().add<Http::Header::AccessControlAllowOrigin>("*"); // CORS
    response.send(Http::Code::Not_Implemented);
}
