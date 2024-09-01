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
    stat(file, &sb);

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