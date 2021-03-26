add_library(machine
    machine/machine_api.cc
    machine/machine.cc
    rest/rest_server.cc
    web/file_handler.cc
    web/frontend.cc
)
target_link_libraries(machine
PUBLIC
    settings
    nlohmann_json::nlohmann_json
    pistache::pistache
)
target_include_directories(machine PUBLIC .)

add_executable(machine-test
    machine/test-machine.cc
)
target_link_libraries(machine-test PRIVATE settings machine doctest::doctest)
add_test(NAME "Machine" COMMAND machine-test)
