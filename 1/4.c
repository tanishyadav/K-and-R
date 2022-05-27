/* Exercise 1-4 */

#include <stdio.h>

/* print celsius-fahrenheit table
 * for celsius = -20, 0, ..., 160 */

int main(void)
{
	float celsius, fahr;
	int lower, upper, step;

	printf("%7s %7s\n", "CELSIUS", "FAHR");

	lower = -20;
	upper = 160;
	step = 20;
	celsius = lower;

	while (celsius <= upper) {
		fahr = (9.0/5.0)*celsius + 32;
		printf("%7.0f %7.1f\n", celsius, fahr);
		celsius = celsius + step;
	}

	return 0;
}
