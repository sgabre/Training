#/Tests/TestFramework/CMakeLists.txt

# Unity Library
add_library(Unity STATIC ${CMAKE_CURRENT_LIST_DIR}/Unity/src/unity.c)
target_include_directories(Unity PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Unity/src)

# CException Library
add_library(CException STATIC ${CMAKE_CURRENT_LIST_DIR}/CException/lib/CException.c)
target_include_directories(CException PUBLIC ${CMAKE_CURRENT_LIST_DIR}/CException/lib)

# CMock Library
add_library(CMock STATIC ${CMAKE_CURRENT_LIST_DIR}/CMock/src/cmock.c)
target_include_directories(CMock PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/CMock/src
    ${CMAKE_CURRENT_LIST_DIR}/Unity/src   # <- essentiel pour #include "unity.h"
)
target_link_libraries(CMock PRIVATE Unity)

add_library(TestFramework INTERFACE)
target_link_libraries(TestFramework INTERFACE Unity CException CMock)