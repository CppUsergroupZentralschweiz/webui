#pragma once

#include <pistache/router.h>

#include <optional>

class Machine;

class MachineApi {
public:
  MachineApi(std::shared_ptr<Machine> machine,
             std::optional<std::string> api_url);

  void get_state(const Pistache::Rest::Request &request,
                 Pistache::Http::ResponseWriter response);
  void get_temperature(const Pistache::Rest::Request &request,
                       Pistache::Http::ResponseWriter response);
  void do_start(const Pistache::Rest::Request &request,
                Pistache::Http::ResponseWriter response);
  void do_stop(const Pistache::Rest::Request &request,
               Pistache::Http::ResponseWriter response);

private:
  void add_cors_headers(Pistache::Http::ResponseWriter &response);

  std::shared_ptr<Machine> _machine;
  std::string _api_url;
};
