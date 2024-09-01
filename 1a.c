/*
============================================================================
Name : 1a.c
Author : Akash Chaudhari
Description : Create the following types of a files using (i) shell command (ii) system call
                a. soft link (symlink system call)
                b. hard link (link system call)
                c. FIFO (mkfifo Library Function or mknod system call)

Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

void soft_link(char *file1, char *file2)
{

    int s_status = symlink(file1, file2);

    if (s_status == 0)
    {
        printf("SoftLink Successfully Created\n");
    }
    else
    {
        perror("Error creating Soft link");
    }
}

int main(int args, char *argv[])
{

    char *file_name = argv[1];
    char *soft_lnk = argv[2];

    soft_link(file_name, soft_lnk);

    return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/1 ❯ cc q1a.c -o q1a                                                                                           22:18:26
~/Documents/Software System/Hands On List/Hands On List 1/1 ❯ ./q1a temp_file softlnk                                                                                   22:18:35
SoftLink Successfully Created
~/Documents/Software System/Hands On List/Hands On List 1/1 ❯ ls -l                                                                                                     22:19:01
total 68
-rw-rw-r-- 1 akash akash   245 Aug 12 23:06 info_q1c.txt
-rwxrwxr-x 1 akash akash 16072 Aug 31 22:18 q1a
-rw-rw-r-- 1 akash akash   603 Aug 27 10:12 q1a.c
-rwxrwxr-x 1 akash akash 16072 Aug 27 10:35 q1b
-rw-rw-r-- 1 akash akash   601 Aug 27 10:12 q1b.c
-rwxrwxr-x 1 akash akash 16072 Aug 27 10:36 q1c
-rw-rw-r-- 1 akash akash   565 Aug 27 10:25 q1c.c
lrwxrwxrwx 1 akash akash     9 Aug 31 22:19 softlnk -> temp_file
-rw-rw-r-- 1 akash akash     7 Aug  8 09:06 temp_file
============================================================================
*/