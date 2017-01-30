#include <stdio.h>

#define MAXLENGTH 100

void mystrcat(char *s, char *t);

int main() 
{
    char s[MAXLENGTH] = "Hello, ";
    char t[MAXLENGTH] = "world!";
    mystrcat(s, t);
    printf("%s\n", s);
}

void mystrcat(char *s, char *t)
{
	/* Copy t to s's tail, implemented with pointers */

	while (*s) {
		s++; /* while (*s++) will move one more than necessary */
	}

	while ((*s++ = *t++)) {  /* same as ((*s++ = *t++) != '\0')*/
		;
	}
	return;
}