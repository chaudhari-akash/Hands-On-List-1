/*
============================================================================
Name : 2.c
Author : Akash Chaudhari
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
			  identify all the process related information in the corresponding proc directory.

Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>

int main(void)
{

	for (;;)
	{
	}
	return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/2 ❯ cc q2.c -o q2
~/Documents/Software System/Hands On List/Hands On List 1/2 ❯ ./q2 &
[1] 8502
~/Documents/Software System/Hands On List/Hands On List 1/2 ❯ stat /proc/8502
  File: /proc/8502
  Size: 0         	Blocks: 0          IO Block: 1024   directory
Device: 0,24	Inode: 51087       Links: 9
Access: (0555/dr-xr-xr-x)  Uid: ( 1000/   akash)   Gid: ( 1000/   akash)
Access: 2024-08-31 22:32:41.844804323 +0530
Modify: 2024-08-31 22:32:41.844804323 +0530
Change: 2024-08-31 22:32:41.844804323 +0530
 Birth: -
============================================================================
*/
