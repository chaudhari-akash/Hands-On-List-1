/*
============================================================================
Name : 27b.c
Author : Akash Chaudhari
Description : Write a program to execute ls -Rl by the following system calls
				a. execl
				b. execlp
				c. execle
				d. execv
				e. execvp

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main()
{

	printf("\tUsing execlp()\n");
	execlp("/bin/ls", "ls", "-Rl", NULL);
	printf("\n");
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/27 ❯ cc q27b.c -o 27b
~/Documents/Software System/Hands On List/Hands On List 1/27 ❯ ./27b
	Using execlp()
.:
total 56
-rwxrwxr-x 1 akash akash 16040 Sep  1 12:06 27a
-rwxrwxr-x 1 akash akash 16040 Sep  1 12:07 27b
-rw-rw-r-- 1 akash akash   506 Aug 31 23:33 q27a.c
-rw-rw-r-- 1 akash akash   508 Aug 31 23:34 q27b.c
-rw-rw-r-- 1 akash akash   270 Aug 30 16:30 q27.c
-rw-rw-r-- 1 akash akash   514 Aug 31 23:34 q27c.c
-rw-rw-r-- 1 akash akash   538 Aug 31 23:34 q27d.c
-rw-rw-r-- 1 akash akash   540 Aug 31 23:34 q27e.c
============================================================================
*/