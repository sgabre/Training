# /Firmware/Module/Dumb/CMakeLists.txt

set(MODULE_NAME Dumb)

set(SOURCES
    Dumb.c
)

add_library(${MODULE_NAME} STATIC ${SOURCES})

target_include_directories(${MODULE_NAME}
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)
