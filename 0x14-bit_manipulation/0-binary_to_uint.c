#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

#include <unistd.h>

/**
 *putchar- writes the character c to stdout
 * @c: The character to print
 *
 *Return: On success 1.on error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 *binary_to_uint- converts binary to unit
 *@b: pointer to binary characher to convert
 *
 *Return: decimal
nsigned int binary_to_uint(const char *b)
{
unsigned int decimal = 0;
unsigned int i; /* Declare 'i' as unsigned int */

if (!b)
return (0);

for (i = 0; b[i] != '\0'; i++)
{
if (b[i] < '0' || b[i] > '1')
return (0);
decimal = 2 * decimal + (b[i] - '0');
}
return (decimal);
}
/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
const char *binary = "101010"; /* Example binary number */
unsigned int result = 0;
unsigned int i; /* Declare 'i' as unsigned int */

if (binary == NULL)
return (0);

for (i = 0; binary[i] != '\0'; i++)
{
if (binary[i] != '0' && binary[i] != '1')
return (0);

result = 2 * result + (binary[i] - '0');
}
result = binary_to_uint(binary); /* Assign the value here */
if (result == 0)
_putchar('0');

else
{
while (result > 0)
{
unsigned int remainder = result % 10; /* Declare 'remainder' as unsigned int */
_putchar(remainder + '0');
result /= 10;
}
}
_putchar('\n');
return (0);
}
