/*
============================================================================
Name : 9.c
Author : Akash Chaudhari
Description : Write a program to print the following information about a given file.
	a. inode
	b. number of hard links
	c. uid
	d. gid
	e. size
	f. block size
	g. number of blocks
	h. time of last access
	i. time of last modification
	j. time of last change


Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
	char *fd = argv[1];
	struct stat sb;
	stat(fd, &sb);

	printf("Inode Number : %lu\n", sb.st_ino);
	printf("Number of Hard Links : %lu\n", sb.st_nlink);
	printf("Uid : %u\n", sb.st_uid);
	printf("Gid : %u\n", sb.st_gid);
	printf("Size : %lu\n", sb.st_size);
	printf("Block Size : %lu\n", sb.st_blksize);
	printf("Number of Blocks : %lu\n", sb.st_blocks);
	printf("Time Of Last Access : %s", ctime(&sb.st_atim.tv_sec));
	printf("Time Of Last Modification : %s", ctime(&sb.st_mtim.tv_sec));
	printf("Time Of Last Change : %s", ctime(&sb.st_ctim.tv_sec));

	return 0;
}