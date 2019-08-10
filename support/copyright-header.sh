#!/usr/bin/env bash

# Install gem with
#     gem install copyright-header

# shellcheck source=./vars.sh
dir=$(dirname "$0")
source "${dir}/project_vars.sh"

git_top=$(git rev-parse --show-toplevel)

if [[ $(git diff --stat) != '' ]]; then
  echo "The git directory is dirty. Fix it first"
  exit
fi

# Glitch: output_dir must be relative
cd "${git_top}" || exit
set -x
copyright-header --license AGPL3 -g \
                 --add-path src:test  \
                 --output-dir . \
                 --copyright-holder "${PROJECT_HOLDER}" \
                 --copyright-software "${PROJECT_NAME}" \
                 --copyright-software-description "${PROJECT_DESCRIPTION}" \
                 --copyright-year "${COPYWRITE_YEARS}"
set +x

# Reset submodules
git submodule foreach git reset --hard

# Reset ext
git checkout HEAD -- src/ext

# Verify that we use the same license
mkdir -p debian
cp LICENSE debian/copyright
git status