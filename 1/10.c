/* Exercise 1-10 */

#include <stdio.h>

/* copy input to output replacing tab by \t, backspace by \b, and backslash by
 * \\ */
int main(void)
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');
		}
		if (c == '\b') {
			putchar('\\');
			putchar('b');
		}
		if (c == '\\') {
			putchar('\\');
			putchar('\\');
		}
		/* I miss `else` :( */
		if (c != '\t')
			if (c != '\b')
				if (c != '\\')
					putchar(c);
	}

	return 0;
}
