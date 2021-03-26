add_executable(webui webui/main.cc)
target_link_libraries(webui PRIVATE settings machine)
