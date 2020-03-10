#!/bin/bash

# Installs C shared library in suitable accessible location
# Invokes CMake install(), which defines install location for
# this library to be /usr/lib. Makes this lib available system wide
# Note: in build dir, install_manifest.txt describes the locations
# at which the make install command applied changes
sudo make install