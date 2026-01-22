# /Firmware/Module/Dummy/CMakeLists.txt

set(MODULE_NAME Dummy)

set(SOURCES
    Dummy.c
)

add_library(${MODULE_NAME} STATIC ${SOURCES})

target_include_directories(${MODULE_NAME}
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)
