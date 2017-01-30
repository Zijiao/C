#include <stdio.h>
#include <string.h>

#define MAXLENGTH 100
#define FALSE 1
#define TRUE 0

int mystrend(char *s, char *t);

int main() 
{
    char s[MAXLENGTH] = "Hello";
    char t[MAXLENGTH] = "l";
    int test = mystrend(s, t);
    printf("%d\n", test);
}

int mystrend(char *s, char *t)
{    
	/* Check whether t appears at end of s */
	/* 0 is succesfully found; 1 is not found */
	int s_len, t_len; /* lengths of string s, t */
    s_len = strlen(s);
    t_len = strlen(t);

    if (t_len == 0 || s_len < t_len) {
    	printf("Not found!");
    	return FALSE;
    }

    while (*s) {
    	s++;
    }
    while (*t) {
    	t++;
    }

    while ((*s-- == *t--) && (t_len > -1)) {
    	/* here is -1 not 0 because curretly t and s are pointing to '\0', one position after the actual last char */
    	t_len--;
    }

    if (t_len == -1) {
    	printf("Found!\n");
    	return TRUE;
    } 
    else {
    	printf("Not found!\n");
    	return FALSE;
    }

}



