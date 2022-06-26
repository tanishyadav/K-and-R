/* Exercise 2-6 */

#include <stdio.h>

/*
 * setbits: return x with the n bits that begin at position p set to the
 * rightmost n bits of y, leaving the other bits unchanged.
 */
unsigned int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y);

int main(void)
{
	unsigned x;
	unsigned y;
	unsigned k;
	unsigned int p;
	unsigned int n;

	for(x = 0; x < 30000; x += 511)
	{
		for(y = 0; y < 1000; y += 37)
		{
			for(p = 0; p < 16; p++)
			{
				for(n = 1; n <= p + 1; n++)
				{
					k = setbits(x, p, n, y);
					printf("setbits(%u, %u, %u, %u) = %u\n", x, p, n, y, k);
				}
			}
		}
	}
	return 0;
}

unsigned int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y)
{
	unsigned int t1, t2, t3;
	/* leftmost bits of x which have to to be left unchanged */
	t1 = x & (~0 << (p+1));
	/* rightmost n bits of y placed at the position p */
	t2 = (y & ~(~0 << n)) << (p-n+1);
	/* rightmost bits of x which have to to be left unchanged */
	t3 = x & ~(~0 << (p-n+1));
	return t1 | t2 | t3;
}
