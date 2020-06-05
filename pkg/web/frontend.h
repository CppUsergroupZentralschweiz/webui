#pragma once

#include <pistache/endpoint.h>

#include <filesystem>
#include <optional>

class Frontend
{
public:
    Frontend(std::optional<std::filesystem::path> ui_folder);

    void start();
    void shutdown();

private:
    std::filesystem::path _ui_folder;
    Pistache::Http::Endpoint _endpoint;

    constexpr static int Threads = 4;
    constexpr static std::uint16_t Port = 3003;
};