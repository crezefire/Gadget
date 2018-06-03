project(gadget-compile-options-public
    VERSION 0.0
    LANGUAGES CXX
)

add_library(gadget-compile-options-public
    INTERFACE
)

add_library(gget::compile-options-public
    ALIAS
        gadget-compile-options-public
)

if (MSVC)
    target_compile_options(gadget-compile-options-public
        INTERFACE
            /Oi         # Enable intrinsic functions
            /std:c++17  # Enable C++ 17 features
    )
elseif (UNIX)
    target_compile_options(gadget-compile-options-public
        INTERFACE
            -std=c++17
    )
endif()

install(
    TARGETS
        gadget-compile-options-public
    EXPORT
        GadgetCompileOptionsPublicTargets
)

install(
    EXPORT
        GadgetCompileOptionsPublicTargets
    FILE
        GadgetCompileOptionsPublicTargets.cmake
    NAMESPACE
        gget::
    DESTINATION
        lib/cmake/GadgetCompileOptionsPublicTargets
)
