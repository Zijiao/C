#include <stdio.h>
#include <string.h>

#define MAXLENGTH 1000

void expand(char s1[], char s2[]);
// expand "a-f" in s1 to "abcdef" in s2

int main()
{
	char s1[MAXLENGTH] = "!-*";
	char s2[MAXLENGTH];
	expand(s1, s2);
	printf("%s\n", s2);

	return 0;
}

void expand(char s1[], char s2[])
{    

    int i, j, k, inc; // i, j are indices for s1 and s2; k is index of startin position of expanding series in s2
    j = k = inc = 0;

    for (i = 0; s1[i+2] != '\0'; i++) {
        if (s1[i] != '-' && s1[i+1] == '-' && s1[i+2] != '-' && s1[i+2] > s1[i]) {
        	for (j = k, inc = 0 ; j < k + s1[i+2] - s1[i] + 1; j++) {
        		s2[j] = s1[i] + inc;
        		inc ++;
        	} 	
        }
        else {
        	s2[j] = s1[i];
        	j++;
        }
        k = j;
    }

    while (i < strlen(s1)) {
    	s2[j++] = s1[i++];
    }
    return;
}



