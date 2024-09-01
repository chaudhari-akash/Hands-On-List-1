/*
============================================================================
Name : 11a.c
Author : Akash Chaudhari
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
			  descriptors and check whether the file is updated properly or not.
				a. use dup
				b. use dup2
				c. use fcntl

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int args, char *argc[])
{

	char *file = argc[1];

	// Opening the File
	int fd = open(file, O_APPEND | O_RDWR);

	// Duplicating the File Descriptor using dup() System Call
	int newfd = dup(fd);

	char *fd_old;
	char *fd_new;

	// Printing the old and the duplicated File Descriptor
	printf("Old File Descriptor : %d\n", fd);
	printf("New File Descriptor : %d\n", newfd);

	// Formatting file descriptors as a string using sprintf and storing it to fd_old and fd_new variables
	sprintf(fd_old, "%d", fd);
	sprintf(fd_new, "%d", newfd);

	write(fd, "\n", 1);

	write(fd, "Old File Descriptor : ", 22);
	write(fd, fd_old, 1);

	write(fd, "\n", 1);

	write(newfd, "New File Descriptor : ", 22);
	write(newfd, fd_new, 1);

	write(fd, "\n", 1);

	return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/11 ❯ ./11a temp.txt
Old File Descriptor : 3
New File Descriptor : 4
============================================================================
*/
