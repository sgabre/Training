# /Firmware/Module/Dumber/CMakeLists.txt

set(MODULE_NAME Dumber)

set(SOURCES
    Dumber.c
)

add_library(${MODULE_NAME} STATIC ${SOURCES})

target_include_directories(${MODULE_NAME}
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)
