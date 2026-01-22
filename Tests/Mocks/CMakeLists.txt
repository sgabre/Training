#/Tests/Mocks/CMakeLists.txt

file(GLOB MOCK_MODULES RELATIVE ${CMAKE_CURRENT_LIST_DIR} *)

foreach(MODULE ${MOCK_MODULES})
    if(
        IS_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/${MODULE}
        AND NOT ${MODULE} STREQUAL "CMakeFiles"
    )
        file(GLOB MOCK_SOURCES
            ${CMAKE_CURRENT_LIST_DIR}/${MODULE}/*.c
        )

        if(MOCK_SOURCES)
            add_library(Mock${MODULE} STATIC ${MOCK_SOURCES})

           target_include_directories(Mock${MODULE} PUBLIC
                ${CMAKE_CURRENT_LIST_DIR}/${MODULE}
                ${PROJECT_SOURCE_DIR}/Firmware/Modules/${MODULE}
            )

            target_link_libraries(Mock${MODULE} PUBLIC
                TestFramework
            )
        endif()
    endif()
endforeach()