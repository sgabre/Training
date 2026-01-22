#/TestHarness/Firmware/Applications/Assembly/CMakeLists.txt

add_executable(Assembly
    main.c
)

target_link_libraries(Assembly
    PRIVATE Dummy
)






