project(gadget-tests
    VERSION 0.0
    LANGUAGES CXX
)

add_executable(gadget-tests
    ${CMAKE_CURRENT_SOURCE_DIR}/error.cpp
)

add_executable(gget::gadget-tests
    ALIAS
        gadget-tests
)

target_link_libraries(gadget-tests
    INTERFACE
        gget::compile-options-private
    PRIVATE
        gget::ext_google_test
        gget::gadget
)
