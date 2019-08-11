option(BP_USE_DOXYGEN "Add a doxygen target to generate the documentation" ON)

#############
## Doxygen ##
#############

if(BP_USE_DOXYGEN)
    find_package(Doxygen OPTIONAL_COMPONENTS dot mscgen dia )
#    if(DOXYGEN_FOUND)
#        set(DOXYGEN_USE_MDFILE_AS_MAINPAGE README.md)
#        set(DOXYGEN_OUTPUT_DIRECTORY docs)
#        set(doxygen_files README.md src)
#        doxygen_add_docs(documentation ${doxygen_files}
#                COMMENT "Generate doxumentation pages"
#                )
#    endif()
    if (DOXYGEN_FOUND)
        # set input and output files
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

        # Configure Doxygen
        set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "HOME.md")
        set(DOXYGEN_SOURCE_BROWSER NO)
        set(DOXYGEN_SHOW_FILES YES)
        set(DOXYGEN_CALL_GRAPH NO)
        set(COLLABORATION_GRAPH NO)

        set(DOXYGEN_INPUT_FILES
                ${CMAKE_CURRENT_SOURCE_DIR}/HOME.md
                ${CMAKE_SOURCE_DIR}/src)

        string (REPLACE ";" " " DOXYGEN_INPUT_FILES_STR "${DOXYGEN_INPUT_FILES}")

        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/footer.in ${CMAKE_CURRENT_SOURCE_DIR}/footer.html)

        add_custom_target(documentation
                COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                COMMENT "Generating API documentation with Doxygen"
                EXCLUDE_FROM_ALL
                VERBATIM)
    endif (DOXYGEN_FOUND)
endif()
