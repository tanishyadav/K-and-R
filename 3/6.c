/* Exercise 3-6 */

#include <stdio.h>
#include <string.h>

#define MAX 100

void itoa(int n, char s[], int width);
void reverse(char s[]);

int main(void)
{
	char out[MAX];
	itoa(3456, out, 6);
	printf("%s\n", out);
	itoa(-3456, out, 6);
	printf("%s\n", out);
	itoa(3456789, out, 6);
	printf("%s\n", out);
	itoa(-34567, out, 6);
	printf("%s\n", out);
	itoa(-3456789, out, 6);
	printf("%s\n", out);
	return 0;
}

void itoa(int n, char s[], int w)
{
	int i;
	unsigned int n2;

	n2 = (n < 0) ? -((long) n) : n;
	i = 0;
	do {
		s[i++] = n2 % 10 + '0';
	} while ((n2 /= 10) > 0);
	if (n < 0)
		s[i++] = '-';
	while (i < w)
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int length = strlen(s);
	int c, i, j;

	for (i = 0, j = length - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
