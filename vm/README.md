# Development VM

## Getting started

First install [vagrant](https://www.vagrantup.com/).
All vagrant commands must be run in folder `vm` containting `Vagrantfile`.

To start the VM run `vagrant up`.

Command `vagrant halt` stops the VM.

With `vagrant destroy` the VM is shutdown and deleted.

## Contents

The VM contains the required toolchains, a browser (chromium) and VS code for editing code.
The code is already checked out under `${HOME}/webui`.
