#!/usr/bin/env bash
set -e
BUILD_DIR="build"
BUILD_BIN="tinyraycaster"

# Take care of dependencies
if [ "$(uname)" == "Darwin" ]; then
  if brew help >/dev/null && ! brew list sdl2 >/dev/null 2>&1 ; then
    brew install sdl2
  fi
elif [ "$(uname)" == "Linux" ]; then
  # Ubuntu/Debian
  if [ -f /etc/lsb-release ] && ! dpkg -l libsdl2-dev >/dev/null ; then
      sudo apt install -y libsdl2-dev
  fi
fi

# Build the project and run it
if [ ! -d "${BUILD_DIR}" ]; then
  mkdir "${BUILD_DIR}"
fi
cd "${BUILD_DIR}"
cmake ..
make
"./${BUILD_BIN}"
