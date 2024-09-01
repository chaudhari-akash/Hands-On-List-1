/*
============================================================================
Name : 4.c
Author : Akash Chaudhari
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.

Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int args, char *argv[])
{

	char *file = argv[1];

	int fd = open(file, O_RDWR | O_EXCL);

	if (fd != -1)
	{
		printf("%s Opened \n", file);
	}
	else
	{
		perror("Error Opening File");
	}

	printf("Value of File Descriptor is : %d\n", fd);

	close(fd);
	return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/4 ❯ cc q4.c -o q4
~/Documents/Software System/Hands On List/Hands On List 1/4 ❯ ./q4 new_openfile.txt
new_openfile.txt Opened
Value of File Descriptor is : 3
============================================================================
*/