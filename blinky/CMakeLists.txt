cmake_minimum_required(VERSION 3.13.1)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(5pmod_blinky)

# Generate compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Target all '.c' files in src folder and include headers in 'include' folder
target_sources(app PRIVATE 
    src/main.c
)
zephyr_include_directories(include/)
