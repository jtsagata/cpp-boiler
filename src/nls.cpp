//
// cpp-boiler - A cpp cmake boilerplate project
// Copyright (C) 2019 Giannis Tsagkatakis <jtsagata@gmail.com>
//
// This file is part of cpp-boiler.
//
// cpp-boiler is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// cpp-boiler is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with cpp-boiler.  If not, see <http://www.gnu.org/licenses/>.
//

#include "nls.h"
#include "config.h"

#include <string>
#include <unistd.h>
#include <climits>

/** @file nls.cpp
 * I18n support for main
 */

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;


std::string getLocalePath() {
  auto path_string = getExePath();
  auto dir = fs::path(path_string).parent_path();
  auto locales = dir / "../share/locale";
  return locales.string();
}
void initNLS() {
  setlocale(LC_ALL, "");
  bindtextdomain(TRANSLATIONS_DOMAIN, getLocalePath().c_str());
  textdomain(TRANSLATIONS_DOMAIN);
}
std::string getExePath() {
  char result[PATH_MAX];
  ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
  auto path_string = std::string(result, (count > 0) ? count : 0);
  return path_string;
}

MoneyOutputter::MoneyOutputter(const char *const locale_name)
    : loc(locale_name), output(std::use_facet<std::money_put<char>>(loc)),
      iterator(os) {
  os.imbue(loc);
  os.setf(std::ios_base::showbase);
}

std::string MoneyOutputter::fmt(double value) {
  os.str(""); // clear string
  output.put(iterator, false, os, ' ', value * 100.0);
  return os.str();
}
