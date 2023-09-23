#include "main.h"

/**
 * error_handler - Handle errors and print messages.
 * @format: A format string for the error message.
 * @...: Additional arguments for the format string.
 */
void error_handler(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	exit(98);
}

/**
 * read_elf_header - Read and display information from an ELF header.
 * @filename: The name of the ELF file to read.
 */
void read_elf_header(const char *filename)
{
	int fd;
	struct ElfHeader header;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_handler("Error: Can't open file %s\n", filename);

	ssize_t bytes_read = read(fd, &header, sizeof(header));

	if (bytes_read < (ssize_t)sizeof(header))
		error_handler("Unable to read ELF header\n");

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", header.e_ident[i], (i == EI_NIDENT - 1) ? '\n' : ' ');

	printf("  Type:                              0x%04x\n", header.e_type);
	printf("  Machine:                           0x%04x\n", header.e_machine);
	printf("  Version:                           0x%08x\n", header.e_version);
	printf("  Entry point address:               0x%08x\n", header.e_entry);

	if (close(fd) == -1)
		error_handler("Error: Can't close fd %d\n", fd);
}

/**
 * main - Entry point of the ELF header display program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
		error_handler("Usage: %s elf_filename\n", argv[0]);

	read_elf_header(argv[1]);

	return (0);
}
