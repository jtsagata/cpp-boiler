#!/usr/bin/env bash

#
# This file is for communication of CMake with the scripts
# be sure to export only general staff
# so no CMAKE_BUILD_TYPE for example
#

git_user=$(git config user.name)
git_email=$(git config user.email)
PROJECT_HOLDER=$(printf "%s <%s>" "$git_user" "$git_email")
COPYWRITE_YEARS=$(date +%Y)


# Automatically populated from Cmake Project
PROJECT_NAME="cpp-boiler"
PROJECT_VERSION="0.0.1"
PROJECT_DESCRIPTION="A cpp cmake boilerplate project"
PROJECT_HOMEPAGE_URL="https://github.com/jtsagata/cpp-boiler"
PROJECT_BUGS_URL="https://jtsagata.github.io/cpp-boiler/issues"
TRANSLATIONS_DOMAIN="cpp-boiler"

