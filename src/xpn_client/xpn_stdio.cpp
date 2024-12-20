
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

#include "base_cpp/debug.hpp"
#include "xpn/xpn_api.hpp"

extern "C" {

FILE * xpn_fopen ( const char *name, const char *mode )
{
  FILE *ret = NULL;

  debug_info("[XPN_STDIO] [xpn_fopen] >> Begin");

  XPN_API_LOCK();
  ret = XPN::xpn_api::get_instance().fopen(name, mode);
  XPN_API_UNLOCK();

  debug_info("[XPN_STDIO] [xpn_fopen] >> End");

  return ret;
}

int xpn_fclose ( FILE *fp )
{
  int ret;

  debug_info("[XPN_STDIO] [xpn_fclose] >> Begin");

  XPN_API_LOCK();
  ret = XPN::xpn_api::get_instance().fclose(fp);
  XPN_API_UNLOCK();

  debug_info("[XPN_STDIO] [xpn_fclose] >> End");

  return ret;
}

size_t xpn_fread ( void *ptr, size_t size, size_t nmemb, FILE *stream )
{
  size_t ret;

  debug_info("[XPN_STDIO] [xpn_fread] >> Begin");

  XPN_API_LOCK();
  ret = XPN::xpn_api::get_instance().fread(ptr, size, nmemb, stream);
  XPN_API_UNLOCK();

  debug_info("[XPN_STDIO] [xpn_fread] >> End");

  return ret;
}

size_t xpn_fwrite ( const void *ptr, size_t size, size_t nmemb, FILE *stream )
{
  size_t ret;

  debug_info("[XPN_STDIO] [xpn_fwrite] >> Begin");

  XPN_API_LOCK();
  ret = XPN::xpn_api::get_instance().fwrite(ptr, size, nmemb, stream);
  XPN_API_UNLOCK();

  debug_info("[XPN_STDIO] [xpn_fwrite] >> End");

  return ret;
}

int xpn_fflush ( FILE *stream )
{
  int ret;

  debug_info("[XPN_STDIO] [xpn_fflush] >> Begin");

  XPN_API_LOCK();
  ret = XPN::xpn_api::get_instance().fflush(stream);
  XPN_API_UNLOCK();

  debug_info("[XPN_STDIO] [xpn_fflush] >> End");

  return ret;
}

int xpn_fseek ( FILE *stream, long int offset, int whence )
{
  int ret;

  debug_info("[XPN_STDIO] [xpn_fseek] >> Begin");

  XPN_API_LOCK();
  ret = XPN::xpn_api::get_instance().fseek(stream, offset, whence);
  XPN_API_UNLOCK();

  debug_info("[XPN_STDIO] [xpn_fseek] >> End");

  return ret;
}

long xpn_ftell ( FILE *stream )
{
  long ret;

  debug_info("[XPN_STDIO] [xpn_ftell] >> Begin");

  XPN_API_LOCK();
  ret = XPN::xpn_api::get_instance().ftell(stream);
  XPN_API_UNLOCK();

  debug_info("[XPN_STDIO] [xpn_ftell] >> End");

  return ret;
}

void xpn_rewind ( FILE *stream )
{
  debug_info("[XPN_STDIO] [xpn_rewind] >> Begin");

  XPN_API_LOCK();
  XPN::xpn_api::get_instance().rewind(stream);
  XPN_API_UNLOCK();

  debug_info("[XPN_STDIO] [xpn_rewind] >> End");
}

int xpn_fgetc ( FILE *stream )
{
  int ret;

  debug_info("[XPN_STDIO] [xpn_fgetc] >> Begin");

  XPN_API_LOCK();
  ret = XPN::xpn_api::get_instance().fgetc(stream);
  XPN_API_UNLOCK();

  debug_info("[XPN_STDIO] [xpn_fgetc] >> End");

  return ret;
}

char * xpn_fgets ( char *s, int tam, FILE *stream )
{
  char * ret;

  debug_info("[XPN_STDIO] [xpn_fgets] >> Begin");

  XPN_API_LOCK();
  ret = XPN::xpn_api::get_instance().fgets(s, tam, stream);
  XPN_API_UNLOCK();

  debug_info("[XPN_STDIO] [xpn_fgets] >> End");

  return ret;
}

int xpn_getc ( FILE *stream )
{
  int ret;

  debug_info("[XPN_STDIO] [xpn_getc] >> Begin");

  XPN_API_LOCK();
  ret = XPN::xpn_api::get_instance().getc(stream);
  XPN_API_UNLOCK();

  debug_info("[XPN_STDIO] [xpn_getc] >> End");

  return ret;
}

int xpn_fileno ( FILE *stream )
{
  int ret;

  debug_info("[XPN_STDIO] [xpn_fileno] >> Begin");

  XPN_API_LOCK();
  ret = XPN::xpn_api::get_instance().fileno(stream);
  XPN_API_UNLOCK();

  debug_info("[XPN_STDIO] [xpn_fileno] >> End");

  return ret;
}

int xpn_ferror ( FILE *stream )
{
  int ret;

  debug_info("[XPN_STDIO] [xpn_ferror] >> Begin");

  XPN_API_LOCK();
  ret = XPN::xpn_api::get_instance().ferror(stream);
  XPN_API_UNLOCK();

  debug_info("[XPN_STDIO] [xpn_ferror] >> End");

  return ret;
}

} // extern "C"
