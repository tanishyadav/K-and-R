/* Exercise 2-8 */

#include <stdio.h>

unsigned int rightrot(unsigned int x, unsigned int n);

int main(void)
{
	/* using gcc binary literals since this is just the driver ;) */
	printf("%x\n", rightrot(0b1010011010011010U, 4U));
	return 0;
}

unsigned int rightrot(unsigned int x, unsigned int n)
{
	return (x >> n) | ((x & ~(~0U << n)) << (sizeof(x)*8 - n));
}
