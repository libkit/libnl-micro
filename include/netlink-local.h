/*
 * netlink-local.h		Local Netlink Interface
 *
 *	This library is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU Lesser General Public
 *	License as published by the Free Software Foundation version 2.1
 *	of the License.
 *
 * Copyright (c) 2003-2008 Thomas Graf <tgraf@suug.ch>
 */

#ifndef NETLINK_LOCAL_H_
#define NETLINK_LOCAL_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <inttypes.h>
#include <assert.h>
#include <limits.h>

#include <arpa/inet.h>
#include <netdb.h>

#ifndef SOL_NETLINK
#define SOL_NETLINK 270
#endif

#include <linux/types.h>

#include <netlink/version.h>
#include <netlink/errno.h>
#include <netlink/types.h>
#include <netlink/list.h>

#define __ADD(id, name) { .i = id, .a = #name },

#define NL_DEBUG	1

#define NL_DBG(LVL,FMT,ARG...) \
	do {} while (0)

#define BUG()                            \
	do {                                 \
		fprintf(stderr, "BUG: %s:%d\n",  \
			__FILE__, __LINE__);         \
		assert(0);	\
	} while (0)

#define ARRAY_SIZE(X) (sizeof(X) / sizeof((X)[0]))
#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

#define __init __attribute__ ((constructor))
#define __exit __attribute__ ((destructor))
#undef __deprecated
#define __deprecated __attribute__ ((deprecated))

#define min(x,y) ({ \
	typeof(x) _x = (x);	\
	typeof(y) _y = (y);	\
	(void) (&_x == &_y);		\
	_x < _y ? _x : _y; })

#define max(x,y) ({ \
	typeof(x) _x = (x);	\
	typeof(y) _y = (y);	\
	(void) (&_x == &_y);		\
	_x > _y ? _x : _y; })


#endif
