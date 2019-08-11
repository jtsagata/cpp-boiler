#
# Translations
#
find_package(Gettext REQUIRED)

set(mo_files)
file(STRINGS "LINGUAS" translated_languages)
foreach (language ${translated_languages})
    set(TRANSLATION_RESULT "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LOCALEDIR}/${language}/LC_MESSAGES/${TRANSLATIONS_DOMAIN}.mo")
    list(APPEND mo_files "${TRANSLATION_RESULT}")
    file(MAKE_DIRECTORY "${CMAKE_INSTALL_LOCALEDIR}/${language}/LC_MESSAGES/")
    add_custom_command(OUTPUT "${TRANSLATION_RESULT}"
            COMMAND ${GETTEXT_MSGFMT_EXECUTABLE} -o "${TRANSLATION_RESULT}" "${language}.po"
            DEPENDS "${language}.po"
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} VERBATIM)
endforeach (language)
add_custom_target(compile-translations ALL DEPENDS ${mo_files})

# All the translation files
# TODO: Write the contents of this to FILES when need it
file(GLOB gettext_source_files
        ${CMAKE_SOURCE_DIR}/test/*.cpp
        ${CMAKE_SOURCE_DIR}/src/*.cpp
        ${CMAKE_SOURCE_DIR}/src/*.h
)


add_custom_command(
        OUTPUT  "${CMAKE_CURRENT_SOURCE_DIR}/${TRANSLATIONS_DOMAIN}.pot"
        COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/update-translations.sh" ${gettext_source_files}
        DEPENDS "${gettext_source_files}" VERBATIM)
add_custom_target(update-translations ALL DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${TRANSLATIONS_DOMAIN}.pot")