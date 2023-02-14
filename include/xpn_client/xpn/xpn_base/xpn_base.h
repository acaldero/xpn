
  /*
   *  Copyright 2000-2023 Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos, Luis Miguel Sanchez Garcia, Borja Bergua Guerra
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

#ifndef _XPN_BASE_H
#define _XPN_BASE_H


 #ifdef  __cplusplus
    extern "C" {
 #endif

   #include "all_system.h"
   #include "base/workers.h"
   #include "nfi/nfi.h"
   #include "nfi/nfi_worker.h"
   #include "nfi/nfi_ops.h"
   #include "nfi/nfi_lib.h"


   #define XPN_CONF "XPN_CONF"
   #define MASK 0000777


/* Paralel struct partition */
struct xpn_partition{
	int id;				/* id of partition */
	int type;			/* type of file :NORMAL, RAID5,... */
	char name[PATH_MAX];	/* name of partition */
	ssize_t block_size;		/* size of distribution used */
	ssize_t size_threads;
	
	int initialized; /* whether it is already initialized or not */

	int data_nserv;			/* number of server */
	struct nfi_server *data_serv;	/* list of data servers in the partition */
	
	int meta_nserv;			/* number of metadata_server */
	struct nfi_server *meta_serv;	/* list of metadata servers in the partition */
};


/* metadata of xpn file */
struct xpn_metadata{
	int sizem;
	int id;
	int version;		/* number of version */
	int type;		/* type of file: file or dir */
	ssize_t block_size;	/* size of distribution used */
	ssize_t size_threads;
	int data_nserv;		/* number of servers */
	int meta_nserv;		/* number of metadata servers */
	struct nfi_attr attr;
	int type_policy;	/* RAID0, RAID1 */
	void *policy;
};


enum xpn_policy{
	POLICY_RAID0,
	POLICY_RAID1
};


struct policy{
	int first_node;
};


 #ifdef  __cplusplus
     }
 #endif

#endif
