#pragma once

#include <pistache/http.h>

#include <filesystem>
#include <vector>

class FileHandler : public Pistache::Http::Handler {
  HTTP_PROTOTYPE(FileHandler)

public:
  FileHandler(std::filesystem::path prefix, std::vector<std::string> resources);

  void onRequest(const Pistache::Http::Request &request,
                 Pistache::Http::ResponseWriter response) override;

private:
  std::filesystem::path _prefix;
  std::vector<std::string> _resources;
};