find_package(Npm REQUIRED)

add_custom_target(ui ALL
  COMMAND ${NPM_EXECUTABLE} run build
  WORKING_DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}
  BYPRODUCTS
    build/index.html
  SOURCES
    package.json
    src/App.js
    src/index.js
    src/index.css
    src/components/machine.js
)

# install(DIRECTORY ui/build/ DESTINATION ui)
