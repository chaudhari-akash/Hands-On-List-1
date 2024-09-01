/*
============================================================================
Name : 1b.c
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

void hard_link(char *file1, char *file2)
{

    int h_status = link(file1, file2);

    if (h_status != -1)
    {
        printf("HardLink Successfully Created\n");
    }
    else
    {
        perror("Error creating Hard link");
    }
}

int main(int args, char *argv[])
{

    char *file_name = argv[1];
    char *soft_lnk = argv[2];

    hard_link(file_name, soft_lnk);

    return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/1 ❯ cc q1b.c -o q1b                                                                                           22:25:59
~/Documents/Software System/Hands On List/Hands On List 1/1 ❯ ./q1b temp_file hardlnk                                                                                   22:26:09
HardLink Successfully Created
~/Documents/Software System/Hands On List/Hands On List 1/1 ❯ ls -l                                                                                                     22:26:23
total 72
-rw-rw-r-- 2 akash akash     7 Aug  8 09:06 hardlnk
-rw-rw-r-- 1 akash akash   245 Aug 12 23:06 info_q1c.txt
-rwxrwxr-x 1 akash akash 16072 Aug 31 22:25 q1a
-rw-rw-r-- 1 akash akash  2131 Aug 31 22:25 q1a.c
-rwxrwxr-x 1 akash akash 16072 Aug 31 22:26 q1b
-rw-rw-r-- 1 akash akash   892 Aug 31 22:25 q1b.c
-rwxrwxr-x 1 akash akash 16072 Aug 27 10:36 q1c
-rw-rw-r-- 1 akash akash   565 Aug 27 10:25 q1c.c
lrwxrwxrwx 1 akash akash     9 Aug 31 22:19 softlnk -> temp_file
-rw-rw-r-- 2 akash akash     7 Aug  8 09:06 temp_file
============================================================================
*/