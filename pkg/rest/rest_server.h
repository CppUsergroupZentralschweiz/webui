#pragma once

#include <pistache/endpoint.h>
#include <pistache/router.h>

#include <memory>

class MachineApi;

class RestServer {
public:
  RestServer(std::shared_ptr<MachineApi> api);

  void start();
  void shutdown();

private:
  std::shared_ptr<MachineApi> _api;

  Pistache::Http::Endpoint _endpoint;
  Pistache::Rest::Router _router;

  constexpr static int Threads = 1;
  constexpr static std::uint16_t Port = 8011;
};
