/*
============================================================================
Name : 14.c
Author : Akash Chaudhari
Description : Write a program to find the type of a file.
                a. Input should be taken from command line.
                b. program should be able to identify any type of a file.

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>

int main(int args, char *argv[])
{
    struct stat sb;
    char *file = argv[1];
    lstat(file, &sb);

    if (S_ISREG(sb.st_mode))
    {
        printf("%s is Regular File.\n", file);
    }
    else if (S_ISDIR(sb.st_mode))
    {
        printf("%s is a Directory.\n", file);
    }
    else if (S_ISCHR(sb.st_mode))
    {
        printf("%s is Character Device.\n", file);
    }
    else if (S_ISBLK(sb.st_mode))
    {
        printf("%s is Block Device.\n", file);
    }
    else if (S_ISFIFO(sb.st_mode))
    {
        printf("%s is FIFO (named pipe).\n", file);
    }
    else if (S_ISLNK(sb.st_mode))
    {
        printf("%s is Symbolic Link.\n", file);
    }
    else if (S_ISSOCK(sb.st_mode))
    {
        printf("%s is Socket.\n", file);
    }
    return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/14 ❯ ls -l
total 20
-rwxrwxr-x 1 akash akash 16040 Aug 29 09:59 14
-rw-rw-r-- 1 akash akash     0 Aug 29 09:50 file.txt
-rw-rw-r-- 1 akash akash  1224 Aug 31 23:11 q14.c
~/Documents/Software System/Hands On List/Hands On List 1/14 ❯ ./14 file.txt
file.txt is Regular File.

============================================================================
*/
