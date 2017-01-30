#include <stdio.h>
#include <string.h>

#define MAXLENGTH 100

void reverse(char s[]);
/* Reverse a string in place */

int main()
{
    char s[MAXLENGTH] = "abcde";
    reverse(s);
    printf("%s\n",s);
}

void reverse(char s[]) 
{
	void reverseHelper(char s[], int l, int h); /* declaration of helper function */
    
    reverseHelper(s, 0, strlen(s) - 1);

    return;
}

void reverseHelper(char s[], int low, int high)
{   
	if (low < high) {
	    char temp;
	    temp = s[low];
	    s[low] = s[high];
	    s[high] = temp;
	    reverseHelper(s, ++low, --high);
	}
	return;
}

