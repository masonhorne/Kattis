#!/bin/bash

function compile() {
    if [ -f src/$1.cpp ]; then
        c++ -std=c++11 src/$1.cpp -o exec/$1
    elif [ -f src/$1.java ]; then
        javac src/$1.java -d exec
    elif [ ! -f src/$1.py ]; then
        echo "Source file doesn't exist: ${1}"
    fi
}

function run() {
    if [ -f exec/$1 ]; then
        ./exec/$1
    elif [ -f exec/Main.class ]; then
        java -cp exec Main
        rm exec/Main.class
    elif [ -f src/$1.py ]; then
        python3 ./src/$1.py
    else
        echo "Executable file doesn't exist: ${1}"
    fi
}

function build() {
    compile $1
    echo "Please paste example input:"
    run $1
}