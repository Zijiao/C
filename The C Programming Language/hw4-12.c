#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 100

void itoa(int n, char s[]);
/* Recursively convert int n to string s */

int main()
{
    int n = 1234;
    char s[MAXLENGTH];
    itoa(n, s);
    printf("%s\n", s);
}

void itoa(int n, char s[]) 
{   

	/* @Zijiao: review */
    static int i;

    /* recersively find the most left digit, than start from left copy each digit to s */
    if (n / 10 != 0) {
    	itoa(n / 10, s);
    }
    else {
    	i = 0;

    	if (n < 0) {
    		/* negative number */
    		s[i++] = '-';
    	} 
    }

    s[i++] = '0' + abs(n) % 10;
    s[i] = '\0';

    return;
}