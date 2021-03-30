find_package(Npm REQUIRED)

add_custom_command(
  OUTPUT
    ${CMAKE_CURRENT_SOURCE_DIR}/node_modules/react/package.json
  COMMAND ${NPM_EXECUTABLE} install
  WORKING_DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "npm install"
)

add_custom_target(build-ui
  COMMAND ${NPM_EXECUTABLE} run build
  WORKING_DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}
  BYPRODUCTS
    build/index.html
  SOURCES
    package.json
    src/App.js
    src/config.js
    src/index.js
    src/index.css
    src/components/machine.js
  DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/node_modules/react/package.json
  COMMENT "npm build"
)
