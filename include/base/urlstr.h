
/*
 *  Copyright 2000-2025 Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos, Luis Miguel Sanchez Garcia, Borja Bergua Guerra
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


#ifndef _URLSTR_H
#define _URLSTR_H

  #ifdef  __cplusplus
    extern "C" {
  #endif


  /* ... Include / Inclusion ........................................... */

     #include "all_system.h"
     #include "string_misc.h"
     #include "path_misc.h"


  /* ... Functions / Funciones ......................................... */

     int ParseURL ( char *url,  
                    char *protocol, 
                    char *login, 
                    char *passwd, 
                    char *server,  
                    char *port,  
                    char *dir) ;


  /* ................................................................... */

  #ifdef  __cplusplus
    }
  #endif

#endif

