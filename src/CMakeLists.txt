###############################################
# Target: config.h                            #
###############################################
configure_file(config.h.in config.h @ONLY)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

###############################################
# Target: BoilerPlate                         #
###############################################

set(BP_SOURCE_FILES main.cpp nls.cpp)
set(BP_INCLUDE_FILES config.h nls.h)

            add_executable(BoilerPlate)
            target_sources(BoilerPlate PRIVATE ${BP_SOURCE_FILES} ${BP_INCLUDE_FILES})
   target_compile_features(BoilerPlate PRIVATE cxx_std_17 cxx_constexpr)
target_include_directories(BoilerPlate PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} )

target_link_libraries(BoilerPlate
        #PUBLIC # Useful for libraries, see https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html for more details about transitive usage requirements.
        #libraries/targets to link when linking this library
        #this will automatically setup the needed flags and dependencies when linking against this target
        # The following libraries are only linked for this target, and its flags/dependencies will not be used when linking against this target
        PRIVATE
        fmt::fmt spdlog::spdlog Boost::filesystem
        # It is possible to link some libraries for debug or optimized builds only
        #debug DEBUGLIBS
        #optimized RELEASELIBS
)

# Helper that can set default warning flags for you
target_set_warnings(BoilerPlate ENABLE ALL AS_ERROR ALL DISABLE Annoying)
# Enable lto if available for non-debug configurations
target_enable_lto(BoilerPlate optimized)