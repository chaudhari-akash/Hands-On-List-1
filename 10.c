/*
============================================================================
Name : 10.c
Author : Akash Chaudhari
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
			  bytes (use lseek) and write again 10 bytes.
				a. check the return value of lseek
				b. open the file with od and check the empty spaces in between the data.


Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char buff[1024];
	int offset;
	int read_size;
	int write_size;

	int fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		perror("Error while opening file! ");
	}
	else
	{
		offset = lseek(fd, 10, SEEK_SET);
		read_size = read(0, buff, 1024);
		write_size = write(fd, buff, read_size);

		offset = lseek(fd, 10, SEEK_CUR);

		read_size = read(0, buff, 1024);

		write(fd, buff, read_size);
	}

	printf("The Return Value of lseek : %d\n", offset);

	return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/10 ❯ cc q10.c -o 10
~/Documents/Software System/Hands On List/Hands On List 1/10 ❯ ./10 temp.txt
Hello

The Return Value of lseek : 26
============================================================================
*/