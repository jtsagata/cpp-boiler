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

/** @file main.cpp
 * Just a simple hello world using libfmt
 */

#include "config.h"
#include "nls.h"
#include <fmt/format.h>
#include <boost/locale.hpp>

int main(int, char *argv[]) {
  MoneyOutputter moneyFmt{};

  // This set the C++ locale
  std::locale::global(std::locale(""));
  // This sets the C locale
  initNLS();


  fmt::print(_("Hello Worlds\n"));

  fmt::print(_("Using locale  '{}'!\n"), std::locale("").name());
  fmt::print(_("hello world from '{}'!\n"), PROJECT_NAME);
  fmt::print(_("Executable : {}\n"), argv[0]);
  fmt::print("A number without {} and with  {:n} locale\n", 20000000000000,
             20000000000000);

  fmt::print("Money without {} and with {} locale\n", -3.14,
             moneyFmt.fmt(-3.14));
  return 0;
}