/*
============================================================================
Name : 18a.c
Author : Akash Chaudhari
Description : Write a program to perform Record locking.
                a. Implement write lock
                b. Implement read lock
              Create three records in a file. Whenever you access a particular record, first lock it then modify/access
              to avoid race condition.

Date: 31th Aug, 2024.
============================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct counter
{
    int number;
};

int main(void)
{

    struct counter c[3];
    int input;

    printf("Enter the Record Number\n");
    printf("1st, 2nd, 3rd: ");
    scanf("%d", &input);
    input--;

    struct flock record;
    record.l_type = F_WRLCK;
    record.l_whence = SEEK_SET;
    record.l_start = input * sizeof(struct counter);
    record.l_len = sizeof(struct counter);
    record.l_pid = getpid();

    int fd = open("db.txt", O_RDWR, 0744);
    if (fd == -1)
    {
        perror("Couldn't Open The File");
        exit(-1);
    }

    lseek(fd, input * sizeof(struct counter), SEEK_SET);

    printf("Waiting to Access the Critical Section\n");

    int status = fcntl(fd, F_SETLKW, &record);

    if (status == -1)
    {
        perror("Locking Unsuccessfull");
        exit(-1);
    }

    printf("File Locking Successfull\n");

    read(fd, &c[input], sizeof(struct counter));

    printf("The current count of Record %d is %d\n", input + 1, c[input].number);

    printf("Increase count by entering 1 \n");
    int temp;
    scanf("%d", &temp);

    if (temp == 1)
    {
        c[input].number++;
        lseek(fd, input * sizeof(struct counter), SEEK_SET);
        write(fd, &c[input], sizeof(struct counter));
        printf("The current count of Record %d is %d\n", input + 1, c[input].number);
    }
    else
    {
        printf("You Entered the Wrong Value\n");
    }
    record.l_type = F_UNLCK;

    fcntl(fd, F_SETLK, &record);

    close(fd);

    return 0;
}