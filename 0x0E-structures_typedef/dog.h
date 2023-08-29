#ifndef _DOG_H_
#define _DOG_H_

#include <stdio.h>
#include <stddef.h>

/**
 * struct dog - struct that creats a dog info
 *
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Description: first struct project
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif
