cmake_minimum_required(VERSION 3.14)

############################
##  Basic Configuration   ##
############################
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "Do not build in-source. Please remove CMakeCache.txt and the CMakeFiles/ directory. Then build out-of-source.")
endif()

include(ProjectParameters.cmake)
project(${PACKAGE_NAME} VERSION ${VERSION} DESCRIPTION ${DESCRIPTION} HOMEPAGE_URL ${REPOSITORY_URL}  LANGUAGES CXX)

configure_file( ${CMAKE_SOURCE_DIR}/support/.project_vars.sh.in
                ${CMAKE_SOURCE_DIR}/support/project_vars.sh @ONLY)

if(NOT EXISTS "${CMAKE_SOURCE_DIR}/README.md")
    configure_file( ${CMAKE_SOURCE_DIR}/support/README_in.md ${CMAKE_SOURCE_DIR}/README.md @ONLY)
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/support/cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/support/cmake/modules)


############################
##  Modules and scripts   ##
############################

# Must be called before adding tests but after calling project().
# This automatically calls enable_testing() and configures ctest targets when using Make/Ninja
include(CTest)

# This is a really useful scripts that creates options that depends on other options.
# It can even be used with generator expressions !
include(CMakeDependentOption)
include(GNUInstallDirs)

# target_enable_lto(mytarget optimized)
include(LTO)

#  target_set_warnings(target
#    [ENABLE [ALL] [list of warning names]]
#    [DISABLE [ALL/Annoying] [list of warning names]]
#    [AS_ERROR ALL]
#  )
include(Warnings)
include(Coverage)
include(Depedencies)

###############
##  OPTIONS  ##
###############
cmake_dependent_option(BP_BUILD_TESTS
        # By default we want tests if CTest is enabled
        "Enable Boilerplate project tests targets" ON
        # Stay coherent with CTest variables
        "BUILD_TESTING" OFF
        )

# It is always easier to navigate in an IDE when projects are organized in folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Check for LTO support (needs to be after project(...) )
find_lto(CXX)

find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif ()

# Help in analysis
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


##########################
##  Add Dubdirectories  ##
##########################
add_subdirectory(src)
add_subdirectory(translations)
add_subdirectory(docs)

