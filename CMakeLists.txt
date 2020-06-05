cmake_minimum_required(VERSION 3.14)

project(WebUi)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_subdirectory(cmd)
add_subdirectory(pkg)
add_subdirectory(ui)
add_subdirectory(vendor EXCLUDE_FROM_ALL)

# Settings
add_library(settings INTERFACE)
target_compile_features(settings INTERFACE cxx_std_17)
target_compile_options(settings INTERFACE -pedantic -Wall -Werror)
