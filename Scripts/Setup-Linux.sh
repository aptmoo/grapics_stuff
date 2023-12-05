#!/bin/bash

if ! command -v premake5 &> /dev/null
then
    echo "Premake5 could not be found. Install it!"
    exit 1
fi

pushd ..
Vendor/Binaries/Premake/Linux/premake5 --cc=clang --file=Build.lua gmake2
popd
