# C++ application with a React web UI

[![Gitpod Ready-to-Code](https://img.shields.io/badge/Gitpod-ready--to--code-blue?logo=gitpod)](https://gitpod.io/#https://github.com/CppUsergroupZentralschweiz/webui)

## Requirements

* C++ compiler supporting C++17
* cmake 3.19 or newer
* [npm](https://www.npmjs.com/)

There is a vagrant config in folder [vm](vm/README.md) to setup a development virtual machine.

## Getting Started

    ./build
    _build/cmd/webui --ui ui/build --url http://localhost:3003

Then open http://localhost:3003 in a browser.

## Development

### Local

Initialize the build directory for the the C++ application.

    cmake -S . -B _build    # -G "Ninja" ...

Build the application, run the tests and run the application.

    cmake --build _build
    ctest --verbose --test-dir _build
    _build/cmd/webui

Initialize the development environment for the React UI.

    cd ui
    npm install

Start the development server for the React UI.
The UI reloads automatically on changes.

    cd ui
    npm start

It may stop on compilation errors, then just start it again.

### Gitpod

[![Open in Gitpod](https://gitpod.io/button/open-in-gitpod.svg)](https://gitpod.io/#https://github.com/CppUsergroupZentralschweiz/webui)

Wait for the container to start.
Once the container is started it will start an initial build of the C++ application and the UI.
Then just use the build command in the status bar.

The React UI should run automatically in a preview window.
If it stops running because of a compilation error it should be restarted.

    cd ui
    REACT_APP_MACHINE_URL=$(gp url 8011) npm start

After building the C++ application open a terminal and start it.

    _build/cmd/webui --url $(gp url 3000)

Use `Ctrl+C` to stop the application.

## Exercises

### Exercise 1

Start machine when pressing start in UI.

Files:
* `pkg/machine/machine_api.cc`

### Exercise 2

Change start button to stop button when the machine is running.
And stop the machine when the stop button is pressed.

Files:
* `pkg/machine/machine_api.cc`
* `pkg/rest/rest_server.cc`
* `ui/src/components/machine.js`

### Exercise 3

Display the current temperature of the machine.

Files:
* `pkg/machine/machine_api.cc`
* `pkg/rest/rest_server.cc`
* `ui/src/components/machine.js`

### Exercise 4

Use a timer in the React UI for polling the temperature each second.

Files:
* `ui/src/components/machine.js`
