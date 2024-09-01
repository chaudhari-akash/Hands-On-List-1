/*
============================================================================
Name : 3.c
Author : Akash Chaudhari
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call

Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int args, char *argv[])
{
	char *file_name = argv[1];

	int fd = creat(file_name, 0666);

	if (fd != -1)
	{
		printf("%s Created \n", file_name);
		printf("Value of File Descriptor is : %d\n", fd);
	}
	else
	{
		perror("File not Created : \n");
	}
	close(fd);
	return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/3 ❯ cc q3.c -o q3                                                                                            22:36:46
~/Documents/Software System/Hands On List/Hands On List 1/3 ❯ ./q3 temp.txt                                                                                            22:36:51
temp.txt Created
Value of File Descriptor is : 3
============================================================================
*/