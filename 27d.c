/*
============================================================================
Name : 27d.c
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

	char *args[] = {"/bin/ls", "-R", "-l", NULL};
	printf("\tUsing excev()\n");
	execv(args[0], args);
	printf("\n");
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/27 ❯ cc q27d.c -o 27d
~/Documents/Software System/Hands On List/Hands On List 1/27 ❯ ./27d
	Using excev()
.:
total 88
-rwxrwxr-x 1 akash akash 16040 Sep  1 12:06 27a
-rwxrwxr-x 1 akash akash 16040 Sep  1 12:07 27b
-rwxrwxr-x 1 akash akash 16040 Sep  1 12:09 27c
-rwxrwxr-x 1 akash akash 16088 Sep  1 12:09 27d
-rw-rw-r-- 1 akash akash   506 Aug 31 23:33 q27a.c
-rw-rw-r-- 1 akash akash   508 Aug 31 23:34 q27b.c
-rw-rw-r-- 1 akash akash   270 Aug 30 16:30 q27.c
-rw-rw-r-- 1 akash akash   514 Aug 31 23:34 q27c.c
-rw-rw-r-- 1 akash akash   538 Aug 31 23:34 q27d.c
-rw-rw-r-- 1 akash akash   540 Aug 31 23:34 q27e.c
============================================================================
*/