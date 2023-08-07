#include "main.h"

/**
 * _power - finds the exponent (power) of an integer
 *
 * @n: integer
 * @pow: exponent
 *
 * Return: n raised to the power pow
 */
int _power(int n, int pow)
{
	int i;
	int solution = 1;

	if (pow != 0)
		for (i = 1; i <= pow; i++)
			solution *= n;
	else
		return (1);

	return (solution);
}

