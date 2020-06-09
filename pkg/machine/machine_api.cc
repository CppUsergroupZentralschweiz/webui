#include "machine/machine_api.h"

#include "machine/machine.h"

using namespace Pistache;

MachineApi::MachineApi(std::shared_ptr<Machine> machine,
                       std::optional<std::string> api_url)
    : _machine{machine}, _api_url{api_url.value_or("http://localhost:3000")} {}

void MachineApi::get_state([[maybe_unused]] const Rest::Request &request,
                           Http::ResponseWriter response) {
  auto const state = _machine->state();

  add_cors_headers(response);
  response.send(Http::Code::Ok, state.dump());
}

void MachineApi::get_temperature([[maybe_unused]] const Rest::Request &request,
                                 Http::ResponseWriter response) {
  add_cors_headers(response);

  // Exercise 3
  // Return the current temperature.
  auto const temperature = _machine->temperature();

  response.send(Http::Code::Ok, temperature.dump());
}

void MachineApi::do_start([[maybe_unused]] const Rest::Request &request,
                          Http::ResponseWriter response) {
  add_cors_headers(response);

  // Exercise 1
  // Start the machine.
  // Return Http::Code::Not_Modified if the machine is already running.
  auto const result = _machine->start();
  if (result["start"] == "already running") {
    response.send(Http::Code::Not_Modified);
  } else {
    response.send(Http::Code::Ok);
  }
}

void MachineApi::do_stop([[maybe_unused]] const Rest::Request &request,
                         Http::ResponseWriter response) {
  add_cors_headers(response);

  // Exercise 2
  // Stop the machine.
  // Return Http::Code::Not_Modified if the machine is not running.
  auto const result = _machine->stop();
  if (result["stop"] == "not running") {
    response.send(Http::Code::Not_Modified);
  } else {
    response.send(Http::Code::Ok);
  }
}

void MachineApi::add_cors_headers(Http::ResponseWriter &response) {
  response.headers().add<Http::Header::AccessControlAllowOrigin>(_api_url);
  response.headers().add<Http::Header::AccessControlAllowMethods>("POST, GET");
}
