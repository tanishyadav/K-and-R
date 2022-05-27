/* Exercise 1-3 */

#include <stdio.h>

int main(void)
{
	float fahr, celsius;
	int lower, upper, step;

	printf("FAHR CELSIUS\n");

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%4.0f %7.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

	return 0;
}
