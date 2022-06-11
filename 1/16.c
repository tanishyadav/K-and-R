/* Exercise 1-16 */

/*
 * NOTE1: I renamed getline to getln because my gcc was complaining
 * NOTE2: In case of more than one contenders for the status of longest line,
 * first one is chosen.
 */

#include <stdio.h>
#define MAXLINE 1000
#define DO   1
#define DONE 0

int getln(char line[], int maxline) ;
void copy(char to[], char from[]);

int main(void)
{
	int len;
	int max;
	int c, state;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	state = DO;
	while ((len = getln(line, MAXLINE)) > 0 && state == DO) {
		if (len == (MAXLINE - 1) && line[MAXLINE - 2] != '\n') {
			while ((c = getchar()) != EOF && c != '\n')
				++len;
			if (c == '\n')
				++len;
			else
				state = DONE;
		}
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)
		printf("%d\n%s", max, longest);

	return 0;
}

/* getln: read a line into s, return length */
int getln(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[])
{
	int i;

	for (i = 0; (to[i] = from[i]) != '\0'; ++i)
		;
}
