/*
============================================================================
Name : 13.c
Author : Akash Chaudhari
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
              verify whether the data is available within 10 seconds or not (check in $man 2 select).

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main()
{
    fd_set fds;
    struct timeval time;
    int status;

    FD_ZERO(&fds);
    FD_SET(0, &fds);

    time.tv_sec = 10;
    status = select(0 + 1, &fds, NULL, NULL, &time);

    if (status == -1)
    {
        perror("Some Error Occured : ");
    }
    else if (status == 0)
    {
        printf("No data available on STDIN within 10 seconds.\n");
    }
    else if (status && FD_ISSET(0, &fds))
    {
        printf("Data is available on STDIN.\n");
    }
    else
    {
        printf("Unexpected result.\n");
    }

    return 0;
}


/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/13 ❯ ./13                                                                                                   
Hello
Data is available on STDIN.
============================================================================
*/