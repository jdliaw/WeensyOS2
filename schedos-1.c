#include "schedos-app.h"
#include "x86sync.h"

/*****************************************************************************
 * schedos-1
 *
 *   This tiny application prints red "1"s to the console.
 *   It yields the CPU to the kernel after each "1" using the sys_yield()
 *   system call.  This lets the kernel (schedos-kern.c) pick another
 *   application to run, if it wants.
 *
 *   The other schedos-* processes simply #include this file after defining
 *   PRINTCHAR appropriately.
 *
 *****************************************************************************/

#ifndef PRINTCHAR
#define PRINTCHAR	('1' | 0x0C00)
#endif

// set priority for 4A
#ifndef MYPRIORITY
#define MYPRIORITY		1
#endif

// set share for 4B
#ifndef MYSHARE
#define MYSHARE		2
#endif

// set tickets for 7
#ifndef TICKETS
#define TICKETS 	25
#endif

// UNCOMMENT THE NEXT LINE TO USE EXERCISE 8 CODE INSTEAD OF EXERCISE 6
// #define __EXERCISE_8__
// Use the following structure to choose between them:
// #infdef __EXERCISE_8__
// (exercise 6 code)
// #else
// (exercise 8 code)
// #endif


void
start(void)
{
	int i;

	sys_priority(MYPRIORITY);
	sys_share(MYSHARE);
	sys_ticket(TICKETS);

	for (i = 0; i < RUNCOUNT; i++) {
		// Write characters to the console, yielding after each one.
		//*cursorpos++ = PRINTCHAR;
		sys_print(PRINTCHAR);
		sys_yield();
	}

	// Yield forever.
	while (1)
		sys_exit(0); // Exercise 2. Exit so don't yield forever. sys_exit needs an arg (int status)
}
