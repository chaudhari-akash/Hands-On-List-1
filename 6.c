/*
============================================================================
Name : 6.c
Author : Akash Chaudhari
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

#define SIZE 1024

int main()
{
	char *buff[SIZE];
	int read_size;

	printf("Start Writing : \n");

	read_size = read(0, buff, SIZE);
	printf("\n");
	write(1, buff, read_size);

	return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/6 ❯ cc q6.c -o q6
~/Documents/Software System/Hands On List/Hands On List 1/6 ❯ ./q6
Start Writing :
Hello This is Question 6

Hello This is Question 6
============================================================================
*/
