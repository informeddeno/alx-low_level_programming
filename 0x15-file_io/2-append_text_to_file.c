#include "main.h"

/**
 * append_text_to_file - append text at the end file
 * @filename: pointer to the file
 * @text_content: string to append to end of file
 *
 * Return: -1 if the function fails or filename is NULL,
 * -1 if the file does not exist or the user lacks write permissions
 * else: 1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int w;
	int len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	w = write(fd, text_content, len);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
