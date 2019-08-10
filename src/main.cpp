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
// The previous block is needed in every file for which you want to generate
// documentation

#include "config.h"
#include <fmt/format.h>

// This should be in the headers

/**
 * @brief A function that does nothing but generate documentation
 * @return The answer to life, the universe and everything
 */
int foo();

int main(int argc, char *argv[]) {
  if (argc) {
    fmt::print("hello world from '{}'!\n", PROJECT_NAME);
    fmt::print("Executable : {}\n", argv[0]);

  }
  return 0;
}

// Implementation
int foo() { return 42; }