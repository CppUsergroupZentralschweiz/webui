# C++ application with a React web UI

## Requirements

* C++ compiler supporting C++17
* cmake 3.14 or newer
* [npm](https://www.npmjs.com/)

There is a vagrant config in folder [vm](vm/README.md) to setup a development virtual machine.

## Getting Started

    ./build
    _build/cmd/webui ui/build

Then open http://localhost:3003 in a browser.

## Development

A terminal for the C++ application

    _build/cmd/webui

and another for the React UI. Reloads automatically on changes.

    cd ui
    npm start

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
