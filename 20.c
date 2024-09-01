/*
============================================================================
Name : 20.c
Author : Akash Chaudhari
Description : Find out the priority of your running program. Modify the priority with nice command.

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main(void)
{

	int priority = getpriority(PRIO_PROCESS, 0);
	printf("Priority of the process is : %d\n", priority);

	int temp;
	printf("Enter the Priority : ");
	scanf("%d", &temp);
	nice(temp);

	int new_priority = getpriority(PRIO_PROCESS, 0);
	printf("Updated Priority of the process is : %d\n", new_priority);

	return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/20 ❯ ./20
Priority of the process is : 0
Enter the Priority : 9
Updated Priority of the process is : 9
~/Documents/Software System/Hands On List/Hands On List 1/20 ❯ sudo ./20
Priority of the process is : 0
Enter the Priority : -17
Updated Priority of the process is : -17
============================================================================
*/