/*
============================================================================
Name : 7.c
Author : Akash Chaudhari
Description : Write a program to copy file1 into file2 ($cp file1 file2).

Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int args, char *argv[])

{
	char buff[1024];
	char *file1 = argv[1];
	char *file2 = argv[2];

	int read_fd = open(file1, O_RDONLY);
	if (read_fd == -1)
	{
		perror("Error opening File 1");
	}

	int write_fd = open(file2, O_RDWR | O_TRUNC | O_CREAT, 0664);
	if (write_fd == -1)
	{
		perror("Error opening File 2");
	}

	int count = read(read_fd, buff, sizeof(buff));
	write(write_fd, buff, count);

	return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/7 ❯ cc q7.c -o q7
~/Documents/Software System/Hands On List/Hands On List 1/7 ❯ ./q7 file1.txt file2.txt
~/Documents/Software System/Hands On List/Hands On List 1/7 ❯ cat file1.txt
This File one Content
~/Documents/Software System/Hands On List/Hands On List 1/7 ❯ cat file2.txt
This File one Content
============================================================================
*/
