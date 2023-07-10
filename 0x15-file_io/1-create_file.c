#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

int create_file(const char *filename, char *text_content);

/**
 * create_file - Create a file and write the provided text content to it.
 *
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, bytes_written = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[bytes_written] != '\0')
			bytes_written++;

		if (write(fd, text_content, bytes_written) == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
