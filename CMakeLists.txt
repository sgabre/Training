#/TestHarness/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(Training VERSION 0.0.0)



# Add Firmware subdirectory for all build types
add_subdirectory(Firmware)

enable_testing()

add_subdirectory(Tests)






