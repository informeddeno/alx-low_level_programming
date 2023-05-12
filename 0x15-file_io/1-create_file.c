#include "main.h"

/**
 * create_file - Creates file
 * @filename: pointer to the file
 * @text_content: pointer to string to write in the file
 *
 * Return: If the function fails - -1
 *         Otherwise - 1
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
int r;
int len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	r = write(fd, text_content, len);

	if (fd == -1 || r == -1)
		return (-1);

	close(fd);

	return (1);
}
