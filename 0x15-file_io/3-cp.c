#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_error- Prints the error message to stderr.
 * @msg: The error message to be printed.
 */
void print_error(const char *msg);

/**
 * copy_file- Copies the content of one file to another file.
 * @file_from: The source file path.
 * @file_to: The destination file path.
 */
int copy_file(const char *file_from, const char *file_to);
void print_error(const char *msg)
{
	write(STDERR_FILENO, msg, strlen(msg));
}

int copy_file(const char *file_from, const char *file_to)
{
	char buf[1024];
	int fd_from, fd_to, ret;
	ssize_t rd;

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		return (98); /* Error: Can't read from file */
	}

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		return (99); /* Error: Can't write to file */
	}

	while ((rd = read(fd_from, buf, sizeof(buf))) > 0)
	{
		ret = write(fd_to, buf, rd);
		if (ret == -1 || ret != rd)
		{
			close(fd_from);
			close(fd_to);
			return (99); /* Error: Can't write to file */
		}
	}

	if (rd == -1)
	{
		close(fd_from);
		close(fd_to);
		return (98); /* Error: Can't read from file */
	}

	ret = close(fd_from);
	if (ret == -1)
	{
		return (100); /* Error: Can't close file */
	}

	ret = close(fd_to);
	if (ret == -1)
	{
		return (100); /* Error: Can't close file */
	}

	return (0);
}

int main(int argc, char *argv[])
{
  int result;

  if (argc != 3)
	{
		print_error("Usage: cp file_from file_to\n");
		return (97); /* Error: Invalid number of arguments */
	}

	result = copy_file(argv[1], argv[2]);

	if (result != 0)
	{
		if (result == 98)
		{
			print_error("Error: Can't read from file\n");
		}
		else if (result == 99)
		{
			print_error("Error: Can't write to file\n");
		}
		else if (result == 100)
		{
			print_error("Error: Can't close file\n");
		}
		return (result);
	}

	return (0);
}
