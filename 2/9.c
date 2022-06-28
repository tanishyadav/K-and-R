/* Exercise 2-9 */

#include <stdio.h>

/* bitcount: count 1 bits in x */
int bitcount(unsigned x);

int main(void)
{

	/* using gcc binary literals since this is just the driver ;) */
	printf("0b10101010: %d\n", bitcount(0b10101010));
	printf("0b10101011: %d\n", bitcount(0b10101011));
	return 0;
}

int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x &= (x-1))
		b++;
	return b;
}
