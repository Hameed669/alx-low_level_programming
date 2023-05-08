#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the number of letters it should read and print
 *
 * Return: the actual number of letters it could read and print
 *         0 if the file can not be opened or read
 *         0 if filename is NULL
 *         0 if write fails or does not write the expected amount of bytes
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	FILE *file = fopen(filename, "a");

	if (file == NULL)
		return (0);

	char *buffer = malloc(letters * sizeof(char));

	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}

	ssize_t bytes_read = fread(buffer, sizeof(char), letters, file);

	if (bytes_read == -1)
	{
		free(buffer);
		fclose(file);
		return (0);
	}

	ssize_t bytes_written = fwrite(buffer, sizeof(char), bytes_read, stdout);

	if (bytes_written != bytes_read)
	{
		free(buffer);
		fclose(file);
		return (0);
	}

	free(buffer);
	fclose(file);

	return (bytes_written);
}
