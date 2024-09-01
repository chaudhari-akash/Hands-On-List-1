/*
============================================================================
Name : 1c.c
Author : Akash Chaudhari
Description : Create the following types of a files using (i) shell command (ii) system call
				a. soft link (symlink system call)
				b. hard link (link system call)
				c. FIFO (mkfifo Library Function or mknod system call)

Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

void make_pipe(const char *pipe_name)
{

	int p_status = mknod(pipe_name, S_IFIFO | 0664, 0);

	if (p_status != -1)
	{
		printf("Named Pipe Created Successfully\n");
	}
	else
	{
		perror("Error creating pipe");
	}
}

int main(int args, char *argv[])
{

	char *pipe_name = argv[1];

	make_pipe(pipe_name);

	return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/1 ❯ cc q1c.c -o q1c                                                                                           22:28:36
~/Documents/Software System/Hands On List/Hands On List 1/1 ❯ ./q1c pipe_1                                                                                              22:28:50
Named Pipe Created Successfully
~/Documents/Software System/Hands On List/Hands On List 1/1 ❯ ls -l                                                                                                     22:28:55
total 72
-rw-rw-r-- 2 akash akash     7 Aug  8 09:06 hardlnk
-rw-rw-r-- 1 akash akash   245 Aug 12 23:06 info_q1c.txt
prw-rw-r-- 1 akash akash     0 Aug 31 22:28 pipe_1
-rwxrwxr-x 1 akash akash 16072 Aug 31 22:25 q1a
-rw-rw-r-- 1 akash akash  2131 Aug 31 22:25 q1a.c
-rwxrwxr-x 1 akash akash 16072 Aug 31 22:26 q1b
-rw-rw-r-- 1 akash akash  2181 Aug 31 22:27 q1b.c
-rwxrwxr-x 1 akash akash 16072 Aug 31 22:28 q1c
-rw-rw-r-- 1 akash akash   990 Aug 31 22:28 q1c.c
lrwxrwxrwx 1 akash akash     9 Aug 31 22:19 softlnk -> temp_file
-rw-rw-r-- 2 akash akash     7 Aug  8 09:06 temp_file

============================================================================
*/