#include "machine/machine.h"

#include <random>

nlohmann::json Machine::state() const {
  nlohmann::json state;

  switch (_state) {
  case State::running:
    state["state"] = "running";
    break;
  case State::idle:
    state["state"] = "idle";
    break;
  case State::off:
    state["state"] = "off";
    break;
  }

  return state;
}

nlohmann::json Machine::temperature() const {
  std::random_device rd{};
  std::mt19937 gen{rd()};
  std::uniform_real_distribution<> dis(-1.0, 1.0);
  auto const variation = dis(gen);

  nlohmann::json result;

  switch (_state) {
  case State::off:
    result["temperature"] = 21.0 + variation;
    break;

  case State::idle:
    result["temperature"] = 25.0 + variation;
    break;

  case State::running:
    result["temperature"] = 42.0 + variation;
    break;
  }

  return result;
}

nlohmann::json Machine::start() {
  nlohmann::json result;
  if (_state == State::running) {
    result["start"] = "already running";
  } else {
    result["start"] = "ok";
    _state = State::running;
  }

  return result;
}

nlohmann::json Machine::stop() {
  nlohmann::json result;
  if (_state == State::running) {
    result["stop"] = "ok";
    _state = State::idle;
  } else {
    result["stop"] = "not running";
  }

  return result;
}
