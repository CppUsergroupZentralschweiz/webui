include(FetchContent)

FetchContent_Declare(
  doctest
  GIT_REPOSITORY  https://github.com/onqtam/doctest.git
  GIT_TAG         2.3.7
)
FetchContent_MakeAvailable(doctest)

FetchContent_Declare(
  trompeloeil
  GIT_REPOSITORY  https://github.com/rollbear/trompeloeil.git
  GIT_TAG         37
)
FetchContent_MakeAvailable(trompeloeil)

FetchContent_Declare(
  json
  GIT_REPOSITORY  https://github.com/nlohmann/json.git
  GIT_TAG         v3.7.3
)
FetchContent_MakeAvailable(json)

add_subdirectory(pistache)
