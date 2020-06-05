#pragma once

#include <nlohmann/json.hpp>

class Machine
{
public:
    nlohmann::json state() const;
    nlohmann::json temperature() const;

    nlohmann::json start();
    nlohmann::json stop();

private:
    enum class State
    {
        off,
        idle,
        running
    };

    State _state{State::off};
};
