#pragma once

#include <pistache/router.h>

class Machine;

class MachineApi
{
public:
    MachineApi(std::shared_ptr<Machine> machine);

    void get_state(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
    void get_temperature(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
    void do_start(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
    void do_stop(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);

private:
    std::shared_ptr<Machine> _machine;
};
