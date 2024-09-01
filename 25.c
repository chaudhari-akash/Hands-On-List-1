/*
============================================================================
Name : 25.c
Author : Akash Chaudhari
Description : Write a program to create three child processes. The parent should wait for a particular child (use
              waitpid system call).

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int child_1 = fork();

    if (child_1 == 0)
    {
        printf("Child 1 PID = %d, Parent PID = %d\n", getpid(), getppid());
    }
    else if (child_1 > 0)
    {
        int child_2 = fork();

        if (child_2 == 0)
        {
            printf("Child 2 PID = %d, Parent PID = %d\n", getpid(), getppid());
        }
        else if (child_2 > 0)
        {
            int child_3 = fork();

            if (child_3 == 0)
            {
                printf("Child 3 PID = %d, Parent PID = %d\n", getpid(), getppid());
            }
            else
            {
                int wait_pid = waitpid(child_3, NULL, 0);
                printf("Parent -> Child 3 [PID = %d] has finished execution.\n", wait_pid);
            }
        }
    }

    return 0;
}

/*
============================================================================
/Documents/Software System/Hands On List/Hands On List 1/25 ❯ cc q25.c -o 25                                                                                           19:07:02
/Documents/Software System/Hands On List/Hands On List 1/25 ❯ ./25

Child 1 PID = 17781, Parent PID = 17780
Child 2 PID = 17782, Parent PID = 17780
Child 3 PID = 17783, Parent PID = 17780
Parent -> Child 3 [PID = 17783] has finished execution.
============================================================================
*/