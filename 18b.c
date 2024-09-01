/*
============================================================================
Name : 18b.c
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
    record.l_type = F_RDLCK;
    record.l_whence = SEEK_SET;
    record.l_start = input * sizeof(struct counter);
    record.l_len = sizeof(struct counter);
    record.l_pid = getpid();

    int fd = open("db.txt", O_RDONLY, 0744);
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

    printf("To Exit Enter 0\n");
    int temp;
    scanf("%d", &temp);

    if (temp != 0)
    {
        printf("Some Error Occured");
    }
    record.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &record);

    close(fd);

    return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/18 ❯ ./18b
Enter the Record Number
1st, 2nd, 3rd: 2
Waiting to Access the Critical Section
File Locking Successfull
The current count of Record 2 is 1
To Exit Enter 0
0
============================================================================
*/