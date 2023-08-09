#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(0)); /* Seed the random number generator with current time */

	char password[12]; /* Password length is 12 characters */
	char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	for (int i = 0; i < 11; i++)
	{
		int index = rand() % (sizeof(charset) - 1);

		password[i] = charset[index];
	}
	password[11] = '\0'; /* Null-terminate the string */

	printf("%s\n", password);

	return (0);
}
