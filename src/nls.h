/* * cpp-boiler - A cpp cmake boilerplate project
 * Copyright (C) 2019 Giannis Tsagkatakis <jtsagata@gmail.com>
 *
 * This file is part of cpp-boiler.
 *
 * cpp-boiler is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * cpp-boiler is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with cpp-boiler.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CPP_BOILER_SRC_NLS_H_
#define CPP_BOILER_SRC_NLS_H_

#include <fmt/locale.h>
#include <libintl.h>
#include <sstream>
#include <string>

/**
 * @brief Translation helper macro
 */
#define _(STRING) gettext(STRING)

/**
 * @brief Call it from main to initialize the NLS system
 */
void initNLS();

/**
 * @brief Find where executable is on the filesystem
 * @return the path to the executable
 */
std::string getExePath();

/**
 * @brief Find the translation dirs according to GNU standards
 * @return the path to the executable
 */
std::string getLocalePath();

class MoneyOutputter {
public:
  explicit MoneyOutputter(const char *const locale_name = "");

  std::string fmt(double value);

private:
  std::locale loc;
  const std::money_put<char> &output;
  std::ostringstream os;
  std::ostreambuf_iterator<char, std::char_traits<char>> iterator;
};

#endif // CPP_BOILER_SRC_NLS_H_
