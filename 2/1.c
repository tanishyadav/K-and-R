/* Exercise 2-1 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	/* char */
	printf("char: min: header: %d\n", CHAR_MIN);
	printf("char: max: header: %d\n", CHAR_MAX);
	/* signed char */
	printf("signed char: min: header: %d\n", SCHAR_MIN);
	printf("signed char: max: header: %d\n", SCHAR_MAX);
	/* unsigned char */
	printf("unsigned char: min: header: NA\n");
	printf("unsigned char: max: header: %u\n", UCHAR_MAX);
	/* short */
	printf("short: min: header: %d\n", SHRT_MIN);
	printf("short: max: header: %d\n", SHRT_MAX);
	/* unsgined short */
	printf("unsigned short: min: header: NA\n");
	printf("unsigned short: max: header: %u\n", USHRT_MAX);
	/* int */
	printf("int: min: header: %d\n", INT_MIN);
	printf("int: max: header: %d\n", INT_MAX);
	/* unsinged int */
	printf("unsigned int: min: header: NA\n");
	printf("unsigned int: max: header: %u\n", UINT_MAX);
	/* long */
	printf("long: min: header: %ld\n", LONG_MIN);
	printf("long: max: header: %ld\n", LONG_MAX);
	/* unsinged long */
	printf("unsigned long: min: header: NA\n");
	printf("unsigned long: max: header: %lu\n", ULONG_MAX);
	return 0;
}
