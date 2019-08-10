#!/usr/bin/env bash

git_user=$(git config user.name)
git_email=$(git config user.email)
PROJECT_HOLDER=$(printf "%s <%s>" "$git_user" "$git_email")
COPYWRITE_YEARS=$(date +%Y)


# Automatically populated from Cmake Project
PROJECT_NAME="cpp-boiler"
PROJECT_VERSION="0.0.1"
PROJECT_DESCRIPTION="A cpp cmake boilerplate project"
PROJECT_HOMEPAGE_URL="https://github.com/jtsagata/cpp-boiler"

