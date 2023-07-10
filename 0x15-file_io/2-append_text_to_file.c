#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, write_status, text_length = 0;
	char *buffer = NULL;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);

	while (text_content[text_length])
		text_length++;

	buffer = malloc((text_length + 1) * sizeof(char));
	if (buffer == NULL)
		return (-1);

	for (int i = 0; i < text_length; i++)
		buffer[i] = text_content[i];
	buffer[text_length] = '\0';

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		free(buffer);
		return (-1);
	}

	write_status = write(fd, buffer, text_length);
	free(buffer);

	if (write_status == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
