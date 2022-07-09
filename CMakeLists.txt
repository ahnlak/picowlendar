cmake_minimum_required(VERSION 3.12)

# Set the project name
set(NAME picowlendar)

include(pimoroni_pico_import.cmake)
include(pico_sdk_import.cmake)

# Gooey boilerplate
project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Source files
add_executable(${NAME}
    main.cpp display.cpp
)

# Slightly messy pull in of libraries we need.
include(../pimoroni-pico/libraries/pico_graphics/pico_graphics.cmake)
include(../pimoroni-pico/libraries/bitmap_fonts/bitmap_fonts.cmake)
include(../pimoroni-pico/libraries/hershey_fonts/hershey_fonts.cmake)
include(../pimoroni-pico/drivers/uc8151/uc8151.cmake)
include(../pimoroni-pico/common/pimoroni_bus.cmake)

# Link in required libraries
target_link_libraries(${NAME}
    pico_stdlib
    pico_graphics
    uc8151
    bitmap_fonts
    hershey_fonts
)

pico_enable_stdio_usb(${NAME} 1)
pico_enable_stdio_uart(${NAME} 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

# Set up files for the release packages
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${NAME}.uf2
    ${CMAKE_CURRENT_LIST_DIR}/README.md
    DESTINATION .
)

set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_GENERATOR "ZIP" "TGZ")
include(CPack)
