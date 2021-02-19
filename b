#!/bin/bash

if [[ -d build/ ]]; then
    rm build -rf
fi

mkdir build
cd build
qmake ..
make
