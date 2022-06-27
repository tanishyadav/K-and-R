/* Exercise 2-7 */

#include <stdio.h>

/*
 * invert: return x with the n bits that begin at position p inverted, leaving
 * the others unchanged.
 */
unsigned int invert(unsigned int x, unsigned int p, unsigned int n);

int main(void)
{
	/* using gcc binary literals since this is just the driver ;) */
	printf("%x\n", invert(0b1010011010011010U, 9U, 4U));
	return 0;
}

unsigned int invert(unsigned int x, unsigned int p, unsigned int n)
{
	unsigned int t1, t2;
	/* x with n bits that begin at position p cleared */
	t1 = x & ((~0U << (p+1)) | ~(~0U << (p-n+1)));
	/* inverted n bits of x that begin at position p */
	t2 = (~(x >> (p-n+1)) & ~(~0U << n)) << (p-n+1);
	return t1 | t2;
}
