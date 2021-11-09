cmake_minimum_required(VERSION 3.20.0)

# Generate compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(smart_led)

# Target all '.c' files in src folder and include headers in 'include' folder
target_sources(app PRIVATE 
    src/main.c
)
zephyr_include_directories(include/)
