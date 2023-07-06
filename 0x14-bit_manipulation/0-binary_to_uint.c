#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: string containing the binary number.
 *
 * Return: converted number, or 0 if there is one or more chars in the string
 * b that is not 0 or 1, or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int convt = 0;
	int i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		convt = 2 * convt + (b[i] - '0');
	}

	return (convt);
}

/**
 * main - entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
	const char *binary = "101010"; /* Example binary number */
	unsigned int result;

	result = binary_to_uint(binary);
	printf("Result: %u\n", result);

	return (0);
}
