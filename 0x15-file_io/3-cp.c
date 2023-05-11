#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: array of arguments
 * error_exit - Prints an error message to stderr and exits with the
 *              specified exit code.
 * @message: The error message format string.
 * @arg:     The argument for the format string.
 * @exit_code: The exit code to use when exiting.
 * This function prints the formatted error message to stderr using
 * dprintf, and then exits the program with the specified exit code.
 *
 * Return: Always 0 (Success)
 */

void error_exit(char *message, char *arg, int exit_code)
{
	dprintf(STDERR_FILENO, message, arg);
	exit(exit_code);
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		error_exit("usage: cp file_from file_to\n", "", 97);
	}

	char *file_from = argv[1];
	char *file_to = argv[2];

	int fd_from = open(file_from, O_RDONLY);

	if (fd_from == -1)
	{
		error_exit("Error: Can't read from file %s\n", file_from, 98);
	}

	int fd_to = open(file_to O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_to == -1)
	{
		error_exit("Error: Can't write to %s\n", file_to, 99);
	}

	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(fd_to, buffer, bytes_read) != bytes_read)
		{
			error_exit("Error: Can't write to %s\n", file_to, 99);
		}
	}
	if (bytes_read == -1)
	{
		error_exit("Error: Can't read from file %s\n", file_from, 98);
	}

	if (close(fd_from) == -1)
	{
		error_exit("Error: Can't close fd %d\n", fd_from, 100);
	}

	if (close(fd_to) == -1)
	{
		error_exit("Error: Can't close fd %d\n", fd_to, 100);
	}

	return (0);
}
