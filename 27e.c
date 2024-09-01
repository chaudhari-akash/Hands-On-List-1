/*
============================================================================
Name : 27e.c
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
	printf("\tUsing execvp()\n");
	execvp(args[0], args);
	printf("\n");
}