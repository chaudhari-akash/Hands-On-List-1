/*
============================================================================
Name : 28.c
Author : Akash Chaudhari
Description : Write a program to get maximum and minimum real time priority.

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sched.h>

int main(void)
{
    int max_priority, min_priority;

    max_priority = sched_get_priority_max(SCHED_FIFO);
    printf("The max priority with SCHED_RR is : %d\n", max_priority);

    min_priority = sched_get_priority_min(SCHED_FIFO);
    printf("The min priority with SCHED_RR is : %d\n", min_priority);

    return 0;
}