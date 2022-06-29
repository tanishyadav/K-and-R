/* Exercise 2-10 */

#include <stdio.h>

char lower(char c);

int main(void)
{
	printf("B: %c\n", lower('B'));
	printf("b: %c\n", lower('b'));
	return 0;
}

char lower(char c)
{
	return (c >= 'A' && c <= 'Z') ? c-'A'+'a' : c;
}
