#include <stdio.h>
#include <stdlib.h>
#include "main.h"

unsigned int binary_to_uint(const char *binary);
int _putchar(char c);

int main(void)
{
    const char *binary = "101010";  /* Example binary number */
    unsigned int decimal = 0;
    unsigned int result; // Move the declaration here
    int i;

    if (binary == NULL)
        return 0;

    for (i = 0; binary[i] != '\0'; i++)
    {
        if (binary[i] != '0' && binary[i] != '1')
            return 0;

        decimal = 2 * decimal + (binary[i] - '0');
    }

    result = binary_to_uint(binary); // Assign the value here

    if (result == 0)
        _putchar('0');
    else
    {
        while (result > 0)
        {
            int remainder = result % 10;
            _putchar(remainder + '0');
            result /= 10;
        }
    }

    _putchar('\n');

    return 0;
}
