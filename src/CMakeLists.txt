if (GADGET_ENABLE_BENCHMARKING)
    add_subdirectory(benchmarks)
    set_property(TARGET gadget-benchmarks PROPERTY FOLDER "src")
endif()

if (GADGET_ENABLE_TESTING)
    add_subdirectory(tests)
    set_property(TARGET gadget-tests PROPERTY FOLDER "src")
endif()
