/*
============================================================================
Name : 21.c
Author : Akash Chaudhari
Description : Write a program, call fork and print the parent and child process id.

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main()
{

	int parent_pid = getpid();
	int child_pid = fork();

	if (child_pid != 0)
	{
		printf("PID of Parent Process : %d\n", parent_pid);
		printf("PID of Child Process : %d\n", child_pid);
	}
	return 0;
}