#!/usr/bin/env bash

base=$(dirname "$0")
git_top=$(git rev-parse --show-toplevel)

# shellcheck disable=SC1090
source "${git_top}/support/project_vars.sh"
cd "${git_top}/translations" || exit

pot_file="${TRANSLATIONS_DOMAIN}.pot"

read -r -d '' xgettext_options <<-EOPTS
    --language=C
    --keyword=_ --keyword=N_ --keyword=C_:1c,2 --keyword=NC_:1c,2
    --sort-output
    --package-name="${PROJECT_NAME}"
    --package-version=${PROJECT_VERSION}
    --msgid-bugs-address="${PROJECT_BUGS_URL}"
    --add-comments="/"
    --escape
EOPTS

#find "${git_top}/src" "${git_top}/tests" -type f -regex ".*\.[ch]\(pp\)?$" -print >> FILES
#git add FILES

#
# Create/update  pot file
#
echo "creating $pot_file"
# shellcheck disable=SC2086
#eval xgettext --files-from=FILES ${xgettext_options} -o "$pot_file"
eval xgettext  ${xgettext_options} -o "$pot_file" "$*"
git add "$pot_file"

#
# Update the language po files and compile
#
linguas=$(cat LINGUAS)
for loc in $linguas; do
  echo "Updating $loc"
  msgmerge --escape --update --sort-output "${loc}.po" "$pot_file"
#  msgfmt --output-file="${loc}.mo" "${loc}.po"
#  git add "${loc}.mo" "${loc}.po"
done

