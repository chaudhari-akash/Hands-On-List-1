/*
============================================================================
Name : 8.c
Author : Akash Chaudhari
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
			  Close the file when end of file is reached.

Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int args, char *argv[])
{

	char buff[1];
	char *file = argv[1];
	int fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		perror("Error Opening File");
	}

	while (read(fd, buff, 1) == 1)
	{

		if (buff[0] == '\n')
		{
			getchar();
		}
		else
		{

			write(1, buff, 1);
		}
	}
	write(1, "\n", 1);
	close(fd);

	return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/8 ❯ cc q8.c -o q8
~/Documents/Software System/Hands On List/Hands On List 1/8 ❯ ./q8 file1.txt
total 20
-rwxrwxr-x 1 akash akash 16176 Aug 27 14:36 a.out
-rw-rw-r-- 1 akash akash     0 Aug 27 14:36 file1.txt
-rw-rw-r-- 1 akash akash   360 Aug 27 14:35 open_read.c

============================================================================
*/
