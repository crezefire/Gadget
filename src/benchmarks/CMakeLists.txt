project(gadget-benchmarks
    VERSION 0.0
    LANGUAGES CXX
)

add_executable(gadget-benchmarks
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(gget::gadget-benchmarks
    ALIAS
        gadget-benchmarks
)

target_link_libraries(gadget-benchmarks
    INTERFACE
        gget::compile-options-private
)

if (MSVC)
    target_link_libraries(gadget-benchmarks
        PRIVATE
            gget::ext_google_benchmark $<$<CONFIG:Release>:-LTCG>
    )
else()
    target_link_libraries(gadget-benchmarks
        PRIVATE
            gget::ext_google_benchmark
    )
endif()
