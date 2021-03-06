#ifndef WEENSYOS_SCHEDOS_H
#define WEENSYOS_SCHEDOS_H
#include "types.h"

/*****************************************************************************
 * schedos.h
 *
 *   Constants and variables shared by SchedOS's kernel and applications.
 *
 *****************************************************************************/

// System call numbers.
// An application calls a system call by causing the specified interrupt.

#define INT_SYS_YIELD		48
#define INT_SYS_EXIT		49
#define INT_SYS_USER1		50
#define INT_SYS_USER2		51
#define INT_SYS_PRIORITY	52 // Exercise 4A
#define INT_SYS_SHARE		53 // Exercise 4B
#define INT_SYS_PRINT		54 // Exercise 6
#define INT_SYS_TICKET		55 // Exercise 7
#define INT_SYS_ACQUIRE		56 // Exercise 8
#define INT_SYS_RELEASE		57 // Exercise 8


// The current screen cursor position (stored at memory location 0x198000).

extern uint16_t * volatile cursorpos;

#endif
