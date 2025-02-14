
/*
 *  Copyright 2020-2024 Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos, Dario Muñoz Muñoz
 *
 *  This file is part of Expand.
 *
 *  Expand is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Expand is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with Expand.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include <dlfcn.h>
#include <string>
#include <stdexcept>
#include <base_cpp/debug.hpp>

#define PROXY(func) \
    ::lookupSymbol<::func>(#func)

static auto getSymbol(const char *name)
{
    auto symbol = ::dlsym(RTLD_NEXT, name);
    if (!symbol)
    {
        std::string errormsg = "dlsym failed to find symbol '";
        errormsg += name;
        errormsg += "'";
        throw std::runtime_error(errormsg);
    }
    return symbol;
}

template <auto T>
static auto lookupSymbol(const char *name)
{
    using return_type = decltype(T);
    static return_type symbol = (return_type)getSymbol(name);
    return symbol;
}