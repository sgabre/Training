#/TestHarness/Firmware/Applications/Idiocracy/CMakeLists.txt

add_executable(Idiocracy
    main.c
)

target_link_libraries(Idiocracy
    PRIVATE Dumb
)






