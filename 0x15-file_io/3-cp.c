#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void print_error(const char *message);
int copy_file(const char *source_file, const char *dest_file);

/*
 * print_error - prints an error message to standard error.
 *
 * @message: The error message to be printed.
 */
void print_error(const char *message)
{
	write(STDERR_FILENO, "Error: ", 7);
	while (*message)
		write(STDERR_FILENO, message++, 1);
	write(STDERR_FILENO, "\n", 1);
}

/*
 * copy_file - Copies the content of one file to another file.
 *
 * @source_file: The source file to copy from.
 * @dest_file: The destination file to copy to.
 *
 * Return: 0 on success, 98 if unable to read from source file, 99 if unable to
 * write to destination file, 100 if unable to close file
 */
int copy_file(const char *source_file, const char *dest_file)
{
	int source_fd, dest_fd;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	source_fd = open(source_file, O_RDONLY);
	if (source_fd == -1)
	{
		print_error("Can't read from file");
		return (98);
	}

	dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (dest_fd == -1)
	{
		print_error("Can't write to file");
		close(source_fd);
		return (99);
	}

	while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written == -1)
		{
			print_error("Write operation failed");
			close(source_fd);
			close(dest_fd);
			return (99);
		}
	}

	if (bytes_read == -1)
	{
		print_error("Read operation failed");
		close(source_fd);
		close(dest_fd);
		return (98);
	}

	if (close(source_fd) == -1)
	{
		print_error("Can't close source file");
		return (100);
	}

	if (close(dest_fd) == -1)
	{
		print_error("Can't close destination file");
		return (100);
	}

	return (0);
}

/*
 * main - Entry point of the program.
 *
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, 97 on incorrect number of arguments, or an error code.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		print_error("Usage: cp file_from file_to");
		exit(97);
	}

	int result = copy_file(argv[1], argv[2]);

	return (result);
}
