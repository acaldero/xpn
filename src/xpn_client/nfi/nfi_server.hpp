
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

#include <string>
#include <memory>
#include <sys/vfs.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <dirent.h>

#include "nfi_xpn_server_comm.hpp"

namespace XPN
{
    // Fordward declaration
    class xpn_fh;
    class xpn_metadata;

    class nfi_server 
    {
    public:
        nfi_server(const std::string &url);
        int init_comm();
        int destroy_comm();

        static std::unique_ptr<nfi_server> Create(const std::string &url);
    public:
        std::string m_protocol; // protocol of the server: mpi_server sck_server
        std::string m_server;   // server address
        std::string m_path;     // path of the server

        int m_error = 0;        // For fault tolerance
    protected:
        const std::string m_url;// URL of this server -> protocol
                                // + server
                                // + path + more info (port, ...)

        std::unique_ptr<nfi_xpn_server_control_comm> m_control_comm;
        nfi_xpn_server_comm                         *m_comm;

    public:
        // Operations 
        virtual int nfi_open        (const std::string &path, int flags, mode_t mode, xpn_fh &fho) = 0; 
        virtual int nfi_create      (const std::string &path, mode_t mode, xpn_fh &fho) = 0;
        virtual int nfi_close       (const xpn_fh &fh) = 0;
        virtual int64_t nfi_read    (const xpn_fh &fh,       char *buffer, int64_t offset, uint64_t size) = 0;
        virtual int64_t nfi_write   (const xpn_fh &fh, const char *buffer, int64_t offset, uint64_t size) = 0;
        virtual int nfi_remove      (const std::string &path, bool is_async) = 0;
        virtual int nfi_rename      (const std::string &path, const std::string &new_path) = 0;
        virtual int nfi_getattr     (const std::string &path, struct ::stat &st) = 0;
        virtual int nfi_setattr     (const std::string &path, struct ::stat &st) = 0;
        virtual int nfi_mkdir       (const std::string &path, mode_t mode) = 0;
        virtual int nfi_opendir     (const std::string &path, xpn_fh &fho) = 0;
        virtual int nfi_readdir     (xpn_fh &fhd, struct ::dirent &entry) = 0;
        virtual int nfi_closedir    (const xpn_fh &fhd) = 0;
        virtual int nfi_rmdir       (const std::string &path, bool is_async) = 0;
        virtual int nfi_statvfs     (const std::string &path, struct ::statvfs &inf) = 0;
        virtual int nfi_read_mdata  (const std::string &path, xpn_metadata &mdata) = 0;
        virtual int nfi_write_mdata (const std::string &path, const xpn_metadata &mdata, bool only_file_size) = 0;
    };
} // namespace XPN