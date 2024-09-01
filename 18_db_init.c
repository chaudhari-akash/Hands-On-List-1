/*
============================================================================
Name : 18_db_init.c
Author : Akash Chaudhari
Description : Write a program to perform Record locking.
                a. Implement write lock
                b. Implement read lock
              Create three records in a file. Whenever you access a particular record, first lock it then modify/access
              to avoid race condition.

Date: 31th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct counter
{
    int number;
};

int main(void)
{

    int fd;
    struct counter db[3];

    for (int i = 0; i < 3; i++)
    {
        db[i].number = 0;
    }

    fd = open("db.txt", O_RDWR);
    write(fd, db, sizeof(db));
    close(fd);

    return 0;
}