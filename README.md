shell
git submodule add https://github.com/ThrowTheSwitch/Unity.git Tests/TestFramework/Unity
git submodule add https://github.com/ThrowTheSwitch/CMock.git Tests/TestFramework/CMock
git submodule add https://github.com/ThrowTheSwitch/CException.git Tests/TestFramework/CException

libUnity

libCMock

libCException


# Add Mocks (Manualy)

## Check the ruby version

```bash
ruby --version
ruby 3.4.2 (2025-02-15 revision d2930f8e7a) +PRISM [arm64-darwin23]
```
## Create mocks for dumber

Create cmock.yml:
```bash
touch cmock.yml
```

Update cmock.yml:
```bash
:cmock:
  :mock_path: Tests/Mocks/Dumber
  :verbosity: 3
  :plugins:
    - :ignore
    - :callback
```

Generate mocks for the Dumber module:
```bash
ruby ./Tests/TestFramework/CMock/lib/cmock.rb -o ./cmock.yml ./Firmware/Modules/Dumber/Dumber.h
```

## Build the libMockDumber

In `./Tests/Mocks/CMakeList.txt`:

```cmake
#/Tests/Mocks/CMakeLists.txt
## Build the Mock Libraries (Generic)

This setup automatically builds one mock library per module.

---

## In `./Tests/Mocks/CMakeLists.txt`

```cmake
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
```

Update `./TestHarness/Firmware/CMakeLists.txt`:

```cmake
#./Tests/CMakeLists.txt
add_subdirectory(TestFramework)
add_subdirectory(Mocks)
add_subdirectory(ComponentTesting)
```
* **Update Dump Component Testing with CMock**

# Add Mocks (Automatically)

