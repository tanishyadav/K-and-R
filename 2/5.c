/* Exercise 2-5 */

#include <stdio.h>

/*
 * any: return the first position in s1 where any character from s2 occurs, or
 * -1 if s1 contatins no characters from s2.
 */
int any(char s1[], char s2[]);

int main(void)
{
	printf("%d\n", any("flisdjlichshuc", "a"));
	printf("%d\n", any("Tanish Yadav", "k"));
	printf("%d\n", any("DJ bravo!", "!b J"));
	printf("%d\n", any("DJ bravo!", "D"));
	printf("%d\n", any("Disco\tBravo", "\t"));
	return 0;
}

int any(char s1[], char s2[])
{
	int i;
	int j;
	int r;
	int brk;

	r = -1;
	brk = 0;
	for (i = 0; s1[i] != '\0' && brk == 0; i++) {
		for (j = 0; s2[j] != '\0' && brk == 0; j++) {
			if (s2[j] == s1[i]) {
				brk = 1;
				r = i;
			}
		}
	}
	return r;
}
