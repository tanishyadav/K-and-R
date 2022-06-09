/* Exercise 1-15 */

#include <stdio.h>

#define LOWER   0
#define UPPER 300
#define STEP   20

float fahr2cel(float fahr);

int main(void)
{
	float fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3.0f %6.1f\n", fahr, fahr2cel(fahr));
}

float fahr2cel(float fahr)
{
	return (5.0 / 9.0) * (fahr - 32);
}
