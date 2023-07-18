#include <stdio.h>

/**
 * main - print numbers separated by commas and spaces
 *
 * Return: (0)
 */
int main(void)
{
	int numbers;

	for (numbers = '0'; numbers <= '9'; numbers++)
	{
		putchar(numbers);

		if (numbers != '9')
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');
	return (0);
}
