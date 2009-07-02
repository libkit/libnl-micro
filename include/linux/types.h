#ifndef _LINUX_TYPES_H
#define _LINUX_TYPES_H

#ifdef linux
#include_next <linux/types.h>
#else

#include <sys/types.h>
#include <stdint.h>

typedef uint8_t __u8;
typedef uint8_t __le8;
typedef uint8_t __be8;

typedef uint16_t __u16;
typedef uint16_t __le16;
typedef uint16_t __be16;

typedef uint32_t __u32;
typedef uint32_t __le32;
typedef uint32_t __be32;

#endif

#endif /* _LINUX_TYPES_H */
