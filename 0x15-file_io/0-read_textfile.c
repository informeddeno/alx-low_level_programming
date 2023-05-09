#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Reads text file
 * @filename: text file
 * @letters: letters to read
 * Return: w- count of bytes read and printed
 *  or  0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *all;
	ssize_t op;
	ssize_t w;
	ssize_t rd;

	op = open(filename, O_RDONLY);
	if (op == -1)
		return (0);
	all = malloc(sizeof(char) * letters);
	rd = read(op, all, letters);
	w = write(STDOUT_FILENO, all, rd);

	free(all);
	close(op);
	return (w);
}
