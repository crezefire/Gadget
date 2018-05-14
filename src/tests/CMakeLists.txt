project(tests
    VERSION 0.0
    LANGUAGES CXX
)

add_executable(tests
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(gget::tests
    ALIAS
        tests
)

target_link_libraries(tests
    INTERFACE
        gget::compile-options-private
    PRIVATE
        gget::ext_google_test
)
