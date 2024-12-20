
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

#include "xpn_path.hpp"

#include <filesystem>
namespace XPN
{
    std::string xpn_path::get_first_dir(const std::string &path)
    {
        std::filesystem::path p(path);

        for (const auto& part : p)
        {
            return part.string();
        }
        return "";
    }

    std::string xpn_path::remove_first_dir(const std::string &path)
    {
        std::filesystem::path p(path);
        std::filesystem::path aux_p;

        int index = 0;
        for (const auto& part : p)
        {
            if (index != 0){
                aux_p /= part;
            }
            index++;
        }
        return aux_p.string();
    }

    int xpn_path::hash(const std::string &path, int max_num, bool is_file)
    {
        
        std::filesystem::path file_path(path);
        
        std::string name;
        if (is_file) {
            name = file_path.filename().string();
        } else {
            name = file_path.parent_path().filename().string();
        }

        int num = 0;
        for (char ch : name) {
            num += static_cast<int>(ch);
        }

        return num % max_num;
     }
}