/*
============================================================================
Name : 26.c
Author : Akash Chaudhari
Description : Write a program to execute an executable program.
				a. use some executable program
				b. pass some input to an executable program. (for example execute an executable of $./a.out name)

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main()
{

	execl("a.out", "a.out", NULL);
	return 0;
}