project(gadget
    VERSION 0.0
    LANGUAGES CXX
)

add_library(gadget
    STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/engine.cpp
)

add_library(gget::gadget
    ALIAS
        gadget
)

target_include_directories(gadget
    PUBLIC
        $<BUILD_INTERFACE:${gadget_BINARY_DIR}/include>
        $<BUILD_INTERFACE:${gadget_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(gadget
    PRIVATE
        gget::compile-options-private
    PUBLIC
        gget::compile-options-public
)

install(
    TARGETS
        gadget
    EXPORT
        GadgetTargets
    LIBRARY DESTINATION
        lib
    ARCHIVE DESTINATION
        lib
    RUNTIME DESTINATION
        bin
    INCLUDES DESTINATION
        include
    PUBLIC_HEADER DESTINATION
        include
)

install(
    DIRECTORY
        include/
    DESTINATION
        include
)

install(
    EXPORT
        GadgetTargets
    FILE
        GadgetTargets.cmake
    NAMESPACE
        gget::
    DESTINATION
        lib/cmake/gadget
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "GadgetConfigVersion.cmake"
    VERSION
        ${gadget_VERSION}
    COMPATIBILITY
        SameMajorVersion
)

install(
    FILES
        "GadgetConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/GadgetConfigVersion.cmake"
    DESTINATION
        lib/cmake/gadget
)

export(
    PACKAGE
        gadget
)
