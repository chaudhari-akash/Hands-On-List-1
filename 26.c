/*
============================================================================
Name : 26.c
Author : Akash Chaudhari
Description : Write a program to execute an executable program.
				a. use some executable program
				b. pass some input to an executable program. (for example execute an executable of $./a.out name)

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main()
{

	execl("a.out", "a.out", NULL);
	return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/26 ❯ cc q26.c -o 26
~/Documents/Software System/Hands On List/Hands On List 1/26 ❯ cc q26a.c
~/Documents/Software System/Hands On List/Hands On List 1/26 ❯ ./26
This Statement is in q26a.c another File.
~/Documents/Software System/Hands On List/Hands On List 1/26 ❯ cc q26b.c
~/Documents/Software System/Hands On List/Hands On List 1/26 ❯ ./26
Enter a Number : 21
The Entered Number is 21.
============================================================================
*/
