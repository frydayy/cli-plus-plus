// -*- C++ -*-
//===--------------------------- exception.hpp ----------------------------===//
//
//  Copyright (c) 2020 Manish sahani
//
//  This program is free software: Licensed under the MIT License. you may not
//  use this file except in compliance with the License. You may obtain a copy
//  of the License at http://www.apache.org/licenses/LICENSE-2.0
//
//===----------------------------------------------------------------------===//
#ifndef CLI_LIB_EXCEPTION_HPP
#define CLI_LIB_EXCEPTION_HPP

#include <string>

namespace cli
{
    namespace properties
    {
        static std::string VERSION = "version";
        static std::string command = "command";
    }

    namespace df
    {
        static std::string version_flag = "-v, --version";
        static std::string version_description = "Display programs for version";
        static std::string help_flag = "-h|--help";
        static std::string help_description = "Display this help message";
    }

    namespace errstr
    {
        namespace option
        {
            static std::string FLAG_EMPTY = "Option flag cannot be empty, Provided an empty string.";
            static std::string INVALID_SYNTAX = "Invalid Syntax for the option";
            static std::string INVALID_ALIASES = "Invalid aliases, only two flags per options are allowed";
            static std::string INVALID_ARG = "Invalid argument provided";
            static std::string ARG_MISSING = "argument required";
        }

        namespace parse
        {
            static std::string MISSING_CMD = "Command not provided";
            static std::string CMD_NOT_FOUND = "Command not found";
            static std::string CMD_MISSING_ARG = "Missing command args";
        }
    }

    namespace Static
    {

        namespace ExceptionStr
        {
            static std::string OPTION_FLAG_EMPTY = "Option flag cannot be empty, Provided an empty string.";
            static std::string PARSE_MISSING_CMD = "Command not provided";
            static std::string PARSE_CMD_NOT_FOUND = "Command not found";
            static std::string PARSE_CMD_MISSING_ARG = "Missing command args";
        } // namespace ExceptionStr
    }     // namespace Static

    struct Exception
    {
        const std::string err;
        const std::string fix;
        const std::string log;

    public:
        Exception(const std::string & e, 
                  const std::string & f = "", 
                  const std::string & l = "") : err(e), fix(f), log(l) {}
        std::string what() const noexcept{ return err; }
        std::string how() const noexcept{ return fix; }
    };

} // namespace cli

#endif