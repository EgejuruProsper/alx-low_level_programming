#include <stdio.h>
/**
 * main - print alphabets without char and user putchar
 *
 * Return: always (0)
 *
 */
int main(void)
{
	int alphabets = '0';

	while (alphabets <= '9')
	{
		putchar(alphabets);
		alphabets++;
	}
		putchar('\n');
		return (0);
}
