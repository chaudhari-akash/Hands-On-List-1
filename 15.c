/*
============================================================================
Name : 15.c
Author : Akash Chaudhari
Description : Write a program to display the environmental variable of the user (use environ).

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	extern char **environ;
	int i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}