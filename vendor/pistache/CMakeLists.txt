find_package(Threads)

FetchContent_Declare(
  pistache
  GIT_REPOSITORY  https://github.com/oktal/pistache.git
  GIT_TAG         73f248ac
)

FetchContent_GetProperties(pistache)
if(NOT pistache_POPULATED)
  FetchContent_Populate(pistache)
endif()

add_library(pistache
  ${pistache_SOURCE_DIR}/src/client/client.cc
  ${pistache_SOURCE_DIR}/src/common/base64.cc
  ${pistache_SOURCE_DIR}/src/common/cookie.cc
  ${pistache_SOURCE_DIR}/src/common/description.cc
  ${pistache_SOURCE_DIR}/src/common/http_defs.cc
  ${pistache_SOURCE_DIR}/src/common/http_header.cc
  ${pistache_SOURCE_DIR}/src/common/http_headers.cc
  ${pistache_SOURCE_DIR}/src/common/http.cc
  ${pistache_SOURCE_DIR}/src/common/mime.cc
  ${pistache_SOURCE_DIR}/src/common/net.cc
  ${pistache_SOURCE_DIR}/src/common/os.cc
  ${pistache_SOURCE_DIR}/src/common/peer.cc
  ${pistache_SOURCE_DIR}/src/common/reactor.cc
  ${pistache_SOURCE_DIR}/src/common/stream.cc
  ${pistache_SOURCE_DIR}/src/common/tcp.cc
  ${pistache_SOURCE_DIR}/src/common/timer_pool.cc
  ${pistache_SOURCE_DIR}/src/common/transport.cc
  ${pistache_SOURCE_DIR}/src/common/utils.cc
  ${pistache_SOURCE_DIR}/src/server/endpoint.cc
  ${pistache_SOURCE_DIR}/src/server/listener.cc
  ${pistache_SOURCE_DIR}/src/server/router.cc
)
add_library(pistache::pistache ALIAS pistache)

target_link_libraries(pistache
  PRIVATE
    settings
    Threads::Threads
)
target_include_directories(pistache PUBLIC ${pistache_SOURCE_DIR}/include)

target_compile_options(pistache PRIVATE "-Wno-defaulted-function-deleted")
