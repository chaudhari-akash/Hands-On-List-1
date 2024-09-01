/*
============================================================================
Name : 12.c
Author : Akash Chaudhari
Description : Write a program to find out the opening mode of a file. Use fcntl.

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>

int main(int args, char *argc[])
{
	char *file = argc[1];

	int fd = open(file, O_WRONLY | O_RDWR);

	int get_mode = fcntl(fd, F_GETFL);
	int mode = 3 & get_mode;
	switch (mode)
	{
	case 0:
		printf("The Opening Mode of a File is READ ONLY ( O_RDONLY )\n");
		break;
	case 1:
		printf("The Opening Mode of a File is WRITE ONLY ( O_WRONLY )\n");
		break;
	case 2:
		printf("The Opening Mode of a File is READ WRITE ( O_RDWR )\n");
		break;
	default:
		perror("Some error Occured\n");
		break;
	}
	return 0;
}




/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/12 ❯ ./12 temp.txt                                                                                          
The Opening Mode of a File is WRITE ONLY ( O_WRONLY )
============================================================================
*/