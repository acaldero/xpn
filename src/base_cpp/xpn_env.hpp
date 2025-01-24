
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

namespace XPN
{
    class xpn_env
    {
    public:
        xpn_env();
        // Delete copy constructor
        xpn_env(const xpn_env&) = delete;
        // Delete copy assignment operator
        xpn_env& operator=(const xpn_env&) = delete;
        // Delete move constructor
        xpn_env(xpn_env&&) = delete;
        // Delete move assignment operator
        xpn_env& operator=(xpn_env&&) = delete;
        int xpn_sck_port = 3456;
        int xpn_controller_sck_port = 34567;
        const char * xpn_conf = nullptr;
        int xpn_debug = 0;
        int xpn_connect_timeout_ms = 5000;
        int xpn_profiler = 0;
        int xpn_thread = 0;
        int xpn_locality = 1;
        int xpn_session_file = 0;
        int xpn_session_dir = 1;
        int xpn_session_connect = 1;
        int xpn_stats = 0;
        const char * xpn_stats_dir = nullptr;
        int xpn_fabric_threads = 10;
    public:
        static xpn_env& get_instance()
        {
            static xpn_env instance;
            return instance;
        }
    };
}