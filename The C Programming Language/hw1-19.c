/* Reverse input lines, one line at a time */


#include <stdio.h>

# define MAXLINE 1000

void reverse(char s[]);
int myGetLine(char s[], int lim);

int test = 101;

int main()
{    

	test = 99;
    char line[MAXLINE];
    int len;
    while((len = myGetLine(line, MAXLINE)) > 0) {
    	reverse(line);
    	printf("%s", line);
    }

    return 0;
}

void reverse(char s[])
{    
	//extern int test;
    printf("%d\n", test); // test 

	/* Reverse a string */
	int i, j;
	char temp;

	i = 0;
	while (s[i] != '\0') {
		++ i; // find the end of string s
	}
	-- i ;
	if (s[i] == '\n') {
		-- i;  // leave new line in place
	}

	j = 0;
    while (j < i) {
    	// swap two chars
    	temp = s[j];
    	s[j] = s[i];
    	s[i] = temp;
    	-- i;
    	++ j;
    }
}

/* Read a line into s, return its length */
int myGetLine(char s[], int lim)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++ i) {
		if (i < lim - 2) {
			s[j] = c; // line still in boundary
			j ++;
		}
        if (c == '\n') {
        	s[j] = c;
        	j ++;
        	i ++;
        }
        s[j] = '\0';
	}
	return i;
}





