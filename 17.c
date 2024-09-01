/*
============================================================================
Name : 17.c
Author : Akash Chaudhari
Description : Write a program to simulate online ticket reservation. Implement write lock
              Write a program to open a file, store a ticket number and exit. Write a separate program, to
              open the file, implement write lock, read the ticket number, increment the number and print
              the new ticket number then close the file.

Date: 31th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    char *file1 = "ticket.txt";

    int fd;
    int status;
    int read_size;
    int write_size;
    int offset;
    int buffer;
    struct flock lock;

    fd = open(file1, O_CREAT | O_RDWR, 0664);

    if (fd < 0)
        perror("Error opening the file : ");
    else
    {
        lock.l_type = F_WRLCK;
        lock.l_pid = getpid();
        lock.l_whence = SEEK_SET;
        lock.l_len = 0;
        lock.l_start = 0;

        status = fcntl(fd, F_SETLKW, &lock);

        if (status < 0)
        {
            perror("Error while Setting lock.");
        }
        else
        {
            printf("Read Lock Set.\n");
            read_size = read(fd, &buffer, sizeof(int));

            if (read_size < 0)
            {
                perror("Error while Reading Ticket.");
            }
            else if (read_size == 0)
            {
                buffer = 1;
                write_size = write(fd, &buffer, sizeof(int));
                if (write_size < 0)
                {
                    perror("Error while Updating Ticket.");
                }
                else
                {
                    printf("Your Ticket Number is : %d\n", buffer);
                }
            }
            else
            {
                offset = lseek(fd, 0, SEEK_SET);
                if (offset < 0)
                    perror("Error in lseek.");
                else
                {
                    buffer += 1;
                    write_size = write(fd, &buffer, sizeof(int));
                    printf("Your Ticket Number is : %d\n", buffer);
                }
            }
            lock.l_type = F_UNLCK;
            status = fcntl(fd, F_SETLKW, &lock);
            if (status < 0)
            {
                perror("Error releasing lock!");
            }
            else
            {
                printf("Lock Released.\n");
            }
        }
    }
    close(fd);
    return 0;
}
