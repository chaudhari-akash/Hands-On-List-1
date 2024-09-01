/*
============================================================================
Name : 27c.c
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

	printf("\tUsing execle()\n");
	execle("/bin/ls", "ls", "-Rl", NULL, NULL);
	printf("\n");
}