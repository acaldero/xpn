
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

#include "nfi/nfi_xpn_server_comm.hpp"

namespace XPN
{
  
  class nfi_fabric_server_comm : public nfi_xpn_server_comm
  {
  public:
    nfi_fabric_server_comm(int& comm) : m_comm(comm) {}

    int64_t write_operation(xpn_server_msg& msg) override;
    int64_t read_data(void *data, int64_t size) override;
    int64_t write_data(const void *data, int64_t size) override;
  public:
    int m_comm;
  };
  
  class nfi_fabric_server_control_comm : public nfi_xpn_server_control_comm
  {
  public:
    nfi_fabric_server_control_comm() = default;
    ~nfi_fabric_server_control_comm() = default;
    
    nfi_xpn_server_comm* connect(const std::string &srv_name) override;
    nfi_xpn_server_comm* connect(const std::string &srv_name, const std::string &port_name) override;
    void disconnect(nfi_xpn_server_comm* comm, bool needSendCode = true) override;

  private:
  };

} // namespace XPN
