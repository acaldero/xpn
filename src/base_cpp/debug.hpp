
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

#include <iostream>
#include <cstring>
#include "xpn_env.hpp"

namespace XPN
{
    #define XPN_DEBUG_COMMON_HEADER std::cerr<<"["<<__func__<<"]["<<__FILE__<<":"<<__LINE__<<"] ";

    #define XPN_DEBUG(out_format) \
    if (xpn_env::get_instance().xpn_debug) { \
        XPN_DEBUG_COMMON_HEADER \
        std::cerr<<out_format<<std::endl;\
    }

    #define XPN_DEBUG_BEGIN_CUSTOM(out_format) XPN_DEBUG("Begin "<<__func__<<"("<<out_format<<")");
    #define XPN_DEBUG_END_CUSTOM(out_format)   XPN_DEBUG("End   "<<__func__<<"("<<out_format<<")="<<(int)res<<", errno="<<errno<<" "<<std::strerror(errno)<<"");
    #define XPN_DEBUG_BEGIN XPN_DEBUG("Begin "<<__func__<<"()");
    #define XPN_DEBUG_END   XPN_DEBUG("End   "<<__func__<<"()="<<(int)res<<", errno="<<errno<<" "<<std::strerror(errno)<<"");

} // namespace XPN