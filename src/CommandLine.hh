/*
 * Copyright 2018 Applied Research Center for Computer Networks
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/** @file */
#pragma once

#include <functional> // function
#include <regex>
#include <utility>
#include <iostream>

// #include <fmt/format.h>
// #include <fmt/ostream.h>

#include "Application.hh"
#include "Loader.hh"


namespace cli {

    using pattern = std::regex;
    using match   = std::cmatch;
    using command = std::function<void(const match&)>;

} // namespace cli

class CommandLine : public Application {
    Q_OBJECT
    SIMPLE_APPLICATION(CommandLine, "command-line-interface")
public:

    CommandLine();
    ~CommandLine();
    void init(Loader* loader, const Config& rootConfig) override;
    void startUp(Loader *) override;

    void registerCommand(cli::pattern&& spec, cli::command&& fn);

    /** Prints a stringto the user. No newline insterted */
    void echo(const std::string& msg)
    {
        std::cout << msg;
    }

    // TODO[dshvetsov] : errors
private:
    struct implementation;
    std::unique_ptr<implementation> m_impl;
};