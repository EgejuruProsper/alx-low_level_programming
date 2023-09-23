#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * error_handler - Handles errors and exits with the specified code.
 * @code: The exit code.
 * @format: The format string for the error message.
 * @...: Additional arguments for the error message.
 */
void error_handler(int code, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	dprintf(STDERR_FILENO, format, args);
	va_end(args);

	exit(code);
}

/**
 * main - Copies the content of one file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t nread, nwritten;
	char buffer[1024];

	if (argc != 3)
		error_handler(97, "Usage: cp file_from file_to\n");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_handler(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_handler(99, "Error: Can't write to %s\n", argv[2]);

	while ((nread = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		nwritten = write(fd_to, buffer, nread);
		if (nwritten == -1 || nread != nwritten)
			error_handler(99, "Error: Can't write to %s\n", argv[2]);
	}

	if (nread == -1)
		error_handler(98, "Error: Can't read from file %s\n", argv[1]);

	if (close(fd_from) == -1)
		error_handler(100, "Error: Can't close fd %d\n", fd_from);

	if (close(fd_to) == -1)
		error_handler(100, "Error: Can't close fd %d\n", fd_to);

	return (0);
}
