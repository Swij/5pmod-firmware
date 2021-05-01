cmake_minimum_required(VERSION 3.13.1)

# Set custom board directory and select the 5pmod_nrf52840 board.
set(BOARD_ROOT ${CMAKE_CURRENT_LIST_DIR}/..)
set(BOARD 5pmod_nrf52840)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(example_5pmod_nrf52840)

# Generate compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Target all '.c' files in src folder and include headers in 'include' folder
FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})
zephyr_include_directories(include/)
