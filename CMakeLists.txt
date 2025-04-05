cmake_minimum_required(VERSION 3.10)
project(interbank-academy-25-fork)

set(CMAKE_CXX_STANDARD 17)

add_executable(interbank_app
    main.cpp
    c_csvreader.cpp
    c_cuckoohashing.cpp
    c_dbmanager.cpp
    c_logicareporte.cpp
)

# add_compile_options(-Wall -Wextra -pedantic)
