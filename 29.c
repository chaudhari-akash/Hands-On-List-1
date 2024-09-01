/*
============================================================================
Name : 29.c
Author : Akash Chaudhari
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,SCHED_RR).

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sched.h>
#include <unistd.h>

int main()
{

	char *policy_arr[3] = {"SCHED_OTHER", "SCHED_FIFO", "SCHED_RR"};

	// Get Scheduling Policy
	int pid = getpid();
	int policy_num = sched_getscheduler(pid);
	printf("The Policy Before modification is : %s\n", policy_arr[policy_num]);

	struct sched_param scheduling_parametre;
	scheduling_parametre.sched_priority = 10;

	int new_policy = 0;

	if (policy_num == 0)
	{
		new_policy = 1;
	}
	else if (policy_num == 1)
	{
		new_policy = 2;
	}
	else if (policy_num == 2)
	{
		new_policy = 0;
	}

	// Set Scheduling Priority
	sched_setscheduler(pid, new_policy, &scheduling_parametre);
	int n_policy = sched_getscheduler(pid);

	if (n_policy == -1)
	{

		perror("Some Error Occured : ");
	}

	printf("The Policy After modification is : %s\n", policy_arr[n_policy]);

	return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/29 ❯ sudo ./29
[sudo] password for akash:
The Policy Before modification is : SCHED_OTHER
The Policy After modification is : SCHED_FIFO
============================================================================
*/