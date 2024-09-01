/*
============================================================================
Name : 19.c
Author : Akash Chaudhari
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long rdtsc()
{
    unsigned long long dst;

    __asm__ __volatile__("rdtsc" : "=A"(dst));
}

int main(void)
{
    unsigned long long start, end;

    start = rdtsc();
    int pid = getpid();
    end = rdtsc();

    int nano_sec = (end - start) / 5;

    printf("The time taken to get pid %d is %d nanoseconds\n", pid, nano_sec);
    return 0;
}