#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include "machine/machine.h"

namespace {

TEST_CASE("Machine is initially off") {
  Machine testee;
  CHECK(testee.state() == R"({"state": "off"})"_json);
}

TEST_CASE("When starting then the machine is running") {
  Machine testee;
  CHECK(testee.start() == R"({"start": "ok"})"_json);
  CHECK(testee.state() == R"({"state": "running"})"_json);
}

TEST_CASE("Starting a running machine keeps running") {
  Machine testee;
  testee.start();

  CHECK(testee.start() == R"({"start": "already running"})"_json);
  CHECK(testee.state() == R"({"state": "running"})"_json);
}

TEST_CASE("When stopping then a running machine is idle") {
  Machine testee;
  testee.start();

  CHECK(testee.stop() == R"({"stop": "ok"})"_json);
  CHECK(testee.state() == R"({"state": "idle"})"_json);
}

TEST_CASE("Stopping an off machine is still off") {
  Machine testee;
  CHECK(testee.stop() == R"({"stop": "not running"})"_json);
  CHECK(testee.state() == R"({"state": "off"})"_json);
}

TEST_CASE("Stopping an idle machine is still idle") {
  Machine testee;
  testee.start();
  testee.stop();

  CHECK(testee.stop() == R"({"stop": "not running"})"_json);
  CHECK(testee.state() == R"({"state": "idle"})"_json);
}

TEST_CASE("Temperature of an off machine is about 21C") {
  Machine testee;

  auto const reponse = testee.temperature();
  REQUIRE(reponse.find("temperature") != reponse.end());

  auto const t = reponse["temperature"].get<double>();
  CHECK(20.0 <= t);
  CHECK(t <= 22.0);
}

TEST_CASE("Temperature of an idle machine is about 25C") {
  Machine testee;
  testee.start();
  testee.stop();

  auto const reponse = testee.temperature();
  REQUIRE(reponse.find("temperature") != reponse.end());

  auto const t = reponse["temperature"].get<double>();
  CHECK(24.0 <= t);
  CHECK(t <= 26.0);
}

TEST_CASE("Temperature of a running machine is about 42C") {
  Machine testee;
  testee.start();

  auto const reponse = testee.temperature();
  REQUIRE(reponse.find("temperature") != reponse.end());

  auto const t = reponse["temperature"].get<double>();
  CHECK(41.0 <= t);
  CHECK(t <= 43.0);
}

} // namespace
