/*
============================================================================
Name : 5.c
Author : Akash Chaudhari
Description : Write a program to create five new files with infinite loop. Execute the program in the background
			  and check the file descriptor table at /proc/pid/fd.

Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	char filename[100];

	for (int count = 1; count < 10000; count++)
	{
		if (count < 6)
		{

			snprintf(filename, sizeof(filename), "File_%d.txt", count);
			int fd = creat(filename, 0644);
			if (fd != -1)
			{
				printf("%s created \n", filename);
			}
			else
			{
				perror("Error creating file");
			}
		}
	}
	while (1)
	{
	}

	return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/5 ❯ cc q5.c -o q5
~/Documents/Software System/Hands On List/Hands On List 1/5 ❯ ./q5 &
[1] 10002
File_1.txt created
File_2.txt created
File_3.txt created
File_4.txt created
File_5.txt created
~/Documents/Software System/Hands On List/Hands On List 1/5 ❯ cd /proc/10002/fd
/proc/10002/fd ❯ ls
0  1  2  3  4  5  6  7
============================================================================
*/