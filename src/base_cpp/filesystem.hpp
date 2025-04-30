
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

#include <unistd.h>

#include <base_cpp/debug.hpp>
#include <base_cpp/proxy.hpp>

namespace XPN {

class filesystem {
   public:
    static ssize_t write(int fd, const void* data, size_t len) {
        ssize_t ret = 0;
        int r;
        int l = len;
        const char* buffer = static_cast<const char*>(data);
        debug_info(">> Begin");

        do {
            r = PROXY(write)(fd, buffer, l);
            if (r <= 0) { /* fail */
                if (ret == 0) ret = r;
                break;
            }

            l = l - r;
            buffer = buffer + r;
            ret = ret + r;

        } while ((l > 0) && (r >= 0));

        debug_info(">> End = " << ret);
        return ret;
    }

    static ssize_t pwrite(int fd, const void* data, size_t len, off_t offset) {
        ssize_t ret = 0;
        int r;
        int l = len;
        off_t off = offset;
        const char* buffer = static_cast<const char*>(data);
        debug_info(">> Begin pwrite(" << fd << ", " << len << ", " << offset << ")");

        do {
            r = PROXY(pwrite)(fd, buffer, l, off);
            if (r <= 0) { /* fail */
                if (ret == 0) ret = r;
                break;
            }

            l = l - r;
            buffer = buffer + r;
            off = off + r;
            ret = ret + r;

        } while ((l > 0) && (r >= 0));

        debug_info(">> End pwrite(" << fd << ", " << len << ", " << offset << ") = " << ret);
        return ret;
    }

    static ssize_t read(int fd, void* data, size_t len) {
        ssize_t ret = 0;
        int r;
        int l = len;
        debug_info(">> Begin");
        char* buffer = static_cast<char*>(data);

        do {
            r = PROXY(read)(fd, buffer, l);
            if (r <= 0) { /* fail */
                if (ret == 0) ret = r;
                break;
            }

            l = l - r;
            buffer = buffer + r;
            ret = ret + r;

        } while ((l > 0) && (r >= 0));

        debug_info(">> End = " << ret);
        return ret;
    }

    static ssize_t pread(int fd, void* data, size_t len, off_t offset) {
        ssize_t ret = 0;
        int r;
        int l = len;
        off_t off = offset;
        debug_info(">> Begin pread(" << fd << ", " << len << ", " << offset << ")");
        char* buffer = static_cast<char*>(data);

        do {
            r = PROXY(pread)(fd, buffer, l, off);
            if (r <= 0) { /* fail */
                if (ret == 0) ret = r;
                break;
            }

            l = l - r;
            buffer = buffer + r;
            off = off + r;
            ret = ret + r;

        } while ((l > 0) && (r >= 0));

        debug_info(">> End  pread(" << fd << ", " << len << ", " << offset << ")= " << ret);
        return ret;
    }
};
}  // namespace XPN