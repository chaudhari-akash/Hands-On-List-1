/*
============================================================================
Name : 26b.c
Author : Akash Chaudhari
Description : Write a program to execute an executable program.
				a. use some executable program
				b. pass some input to an executable program. (for example execute an executable of $./a.out name)

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>

int main(void)
{
    int num;
    printf("Enter a Number : ");
    scanf("%d", num);
    printf("The Entered Number is %d.\n", num);

    return 0;
}
