include(FetchContent)

FetchContent_Declare(
  doctest
  GIT_REPOSITORY  https://github.com/onqtam/doctest.git
  GIT_TAG         2.4.6
)

FetchContent_Declare(
  trompeloeil
  GIT_REPOSITORY  https://github.com/rollbear/trompeloeil.git
  GIT_TAG         v40
)

FetchContent_Declare(
  json
  GIT_REPOSITORY  https://github.com/nlohmann/json.git
  GIT_TAG         v3.9.1
)

FetchContent_Declare(
  ixwebsocket
  GIT_REPOSITORY  https://github.com/machinezone/IXWebSocket.git
  GIT_TAG         v11.2.4
)

set(JSON_BuildTests OFF)

FetchContent_MakeAvailable(doctest trompeloeil json ixwebsocket)

add_library(ixwebsocket::ixwebsocket ALIAS ixwebsocket)

add_subdirectory(pistache)
