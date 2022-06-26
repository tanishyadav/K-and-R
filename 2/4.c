/* Exercise 2-4 */

#include <stdio.h>

/*
 * squeeze: remove each character in s1 which matches any character in s2.
 */
void squeeze(char s1[], char s2[]);

int main(void)
{
	char t1[] = "flisdjlichshuc";
	squeeze(t1, "a");
	printf("%s\n", t1);
	char t2[] = "Tanish Yadav";
	squeeze(t2, "k");
	printf("%s\n", t2);
	char t3[] = "DJ bravo!";
	squeeze(t3, " !b");
	printf("%s\n", t3);
	char t4[] = "DJ bravo!";
	squeeze(t4, "D");
	printf("%s\n", t4);
	char t5[] = "Disco\tBravo";
	squeeze(t5, "\t");
	printf("%s\n", t5);
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i;
	int j;
	int k;
	int yes;

	for (i = j = 0; s1[i] != '\0'; i++) {
		yes = 0;
		for (k = 0; s2[k] != '\0'; k++)
			if (s2[k] == s1[i])
				yes = 1;
		if (yes == 0)
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}
