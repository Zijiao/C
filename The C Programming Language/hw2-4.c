#include <stdio.h>

#define MAXLENGTH 100


void squeeze(char s1[], char s2[]); 
// delete any char in s1 that also appears in s2; O(n^2)

int main()
{
    char s1[MAXLENGTH] = "hello";
    char s2[MAXLENGTH] = "world";
    squeeze(s1, s2);
    printf("%s\n", s1);
}

void squeeze(char s1[], char s2[])
{
    int i, j, k; // i, j are indices for s1, s2; k is indices for non-overlap position in s1

    for (i = k = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; j++) {
            ;
        }
        if (s2[j] == '\0') {
        	s1[k++] = s1[i];
        }
    }

    for (i = k; s1[i] != '\0'; i++) {
    	s1[i] = '\0';
    }

}