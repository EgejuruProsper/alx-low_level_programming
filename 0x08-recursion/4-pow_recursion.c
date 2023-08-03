#include "main.h"

/**
 * _pow_recursion - Returns the value of x raised to power y.
 * @x: The base number.
 * @y: The exponent.
 *
 * Return: The value of x raised to power y if x > y
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, y - 1));
}
