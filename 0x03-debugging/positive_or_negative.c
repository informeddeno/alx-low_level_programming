#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * positive_or_negative - Prints if number is positive, negative or zero.
 *@i : integer
 * Return: Always 0 (Success)
 */
void positive_or_negative(int i)
{
	if (i > 0)
	{
		printf("%d is positive\n", i);
	}
	else if (i == 0)
	{
		printf("%d is zero\n", i);
	}
	else
	{
		printf("%d is negative\n", i);
	}
}
