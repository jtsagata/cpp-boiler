#!/usr/bin/env bash
# shellcheck disable=SC2035

base=$(dirname "$0")
git_top=$(git rev-parse --show-toplevel)

pushd "${base}/gitignore" || exit
cat *  >"${git_top}/.gitignore"
git add . "${git_top}/.gitignore"

popd || exit
git status
