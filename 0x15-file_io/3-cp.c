#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#define BUFFER_SIZE 1024

/**
 * exit_error - Prints an error message and exits with the specified code
 * @exit_code: The exit code to use
 * @message: The error message to print
 */
void exit_error(int exit_code, char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(exit_code);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: 0 on success, otherwise an error code
 */
int main(int argc, char *argv[])
{
	int src_fd, dest_fd, read_bytes, write_bytes;
	char *buffer;

	if (argc != 3)
		exit_error(97, "Usage: cp file_from file_to");

	src_fd = open(argv[1], O_RDONLY);
	if (src_fd == -1)
		exit_error(98, "Error: Can't read from source file");

	dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (dest_fd == -1)
		exit_error(99, "Error: Can't write to destination file");

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
		exit_error(99, "Error: Unable to allocate memory");

	while ((read_bytes = read(src_fd, buffer, BUFFER_SIZE)) > 0)
	{
		write_bytes = write(dest_fd, buffer, read_bytes);
		if (write_bytes != read_bytes || write_bytes == -1)
			exit_error(99, "Error: Can't write to destination file");
	}

	if (read_bytes == -1)
		exit_error(98, "Error: Can't read from source file");

	free(buffer);

	if (close(src_fd) == -1)
		exit_error(100, "Error: Can't close source file descriptor");

	if (close(dest_fd) == -1)
		exit_error(100, "Error: Can't close destination file descriptor");

	return (0);
}
