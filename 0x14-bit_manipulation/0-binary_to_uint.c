#include <stdio.h>
#include <stdlib.h>
#include "main.h"

unsigned int binary_to_uint(const char *b);

int main(void)
{
	const char *binary = "101010";  /* Example binary number */
	unsigned int convt = 0;
	int i;

	if (binary == NULL)
		return (0);

	for (i = 0; binary[i] != '\0'; i++)
	{
		if (binary[i] != '0' && binary[i] != '1')
			return (0);

		convt = 2 * convt + (binary[i] - '0');
	}

	binary_to_uint(binary);

	return (0);
}
