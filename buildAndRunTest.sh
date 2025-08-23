#!/bin/bash

mkdir -p testfolder
cd testfolder
cmake ../tests
cmake --build .
./tests