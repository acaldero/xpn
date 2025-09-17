
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

#include "workers.hpp"

#include <iostream>

#include "workers_sequential.hpp"
#include "workers_pool.hpp"
#include "workers_on_demand.hpp"

namespace XPN
{
    std::unique_ptr<workers> workers::Create(workers_mode mode, bool with_limits)
    {
        switch (mode)
        {
            case workers_mode::sequential: return std::make_unique<workers_sequential>();
            case workers_mode::thread_pool: return std::make_unique<workers_pool>();
            case workers_mode::thread_on_demand: return std::make_unique<workers_on_demand>(with_limits);
            default: std::cerr<<"Error: workers mode '"<<static_cast<int>(mode)<<"' not defined"<<std::endl; break;
        }
        return nullptr;
    }
} // namespace XPN
