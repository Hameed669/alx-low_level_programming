#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

void print_error_and_exit(const char* msg, const char* file_name, int exit_code)
{
	dprintf(STDERR_FILENO, msg, file_name);
	exit(exit_code);
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		print_error_and_exit("Usage: %s file_from file_to\n", argv[0], 97);
	}

	int from_fd = open(argv[1], O_RDONLY);
	if (from_fd == -1)
	{
		print_error_and_exit("Error: Can't read from file %s\n", argv[1], 98)
	}

	int to_fd open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR 
			| S_IRGRP | S_IWGRP | S_IROTH);
	if (to_fd == -1)
	{
		print_error_and_exit("Error: Can't write to %s\n", argv[2], 99);
	}

	char buffer[BUF_SIZE];
	ssize_t num_read, num_written;
	while ((num_read = read(from_fd, buffer, BUF_SIZE)) > 0);
	{
		num_written = write(to_fd, buffer, num_read);
		if(num_written == -1 || num_written != num_read)
		{
			print_error_and_exit("Error: Can't write to %s\n", argv[2], 99);
		}
	}
	if (num_read == -1)
	{
		print_error_and_exit("Error: Can't read from file %s\n", argv[1], 98);
	}

	if (close(from_fd) == -1)
	{
		print_error_and_exit("Error: Can't close fd %d\n", from_fd, 100);
	}

	if (close(to_fd) == -1)
	{
		print_error_and_exit("Error: Can't close fd %d\n", to_fd, 100);
	}

	return (0);
}

