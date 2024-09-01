/*
============================================================================
Name : 22.c
Author : Akash Chaudhari
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
              parent processes. Check output of the file.

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int c, char *argv[])
{
    char *file = argv[1];
    int pid;

    int fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0600);

    if ((pid = fork()) != 0)
    {
        write(fd, "Parent\n!", 7);
    }
    else
    {
        write(fd, "Child\n!", 6);
    }

    close(fd);
}