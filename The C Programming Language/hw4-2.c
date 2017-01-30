#include <stdio.h>
#include <ctype.h>

#define MAXLENGTH 100

double atof(char s[]);

int main()
{
    char s[MAXLENGTH] = "aa";
    double val = atof(s);
    printf("%f\n", val);	
}

double atof(char s[])
{
	/* string to double; can deal with scientific notation (like 1e-2 -> "0.02") */
	/* no validity check, illegal input will return 0.0 */

	double val, power; /* power is actually inverse-power (val = val / power) */
	int sign, e, i;
    
    /* skip leading blank spaces */
    for (i = 0; isspace(s[i]); i++) {
    	;
    }

    /* get the sign */
    sign = (s[i] == '-') ? -1 : 1;

    /* if current position is a '+'' or '-', move pointer to the next */
    if (s[i] == '-' || s[i] == '+') {
    	i++;
    }

    for (val = 0.0; isdigit(s[i]); i++) {
    	val = 10.0 * val + (s[i] - '0'); /* get integer part */
    }
    
    /* deal with decimal point */ 
    if (s[i] == '.') {
        i++;
        for (power = 1.0; isdigit(s[i]); i++) {
    	    /* first add on all digits, then divided by power */
    	    val = 10.0 * val + (s[i] - '0');
    	    power *= 10.0;
        }
        val = sign * val / power;
    }


    /* Below deal with scientific notation ('e' in "1e-2") */
    if (s[i] == 'e' || s[i] == 'E') {
    	i++;

        sign = (s[i] == '-') ? -1: 1;
        /* also need to move the pointer */
        if (s[i] == '-' || s[i] == '+') {
        	i++;
        }

        for (e = 0; isdigit(s[i]); i++) {
        	/* similar to val */
            e = e * 10 + (s[i] - '0');
        }

        /* apply sign to val */
        if (sign == 1) {
        	while (e -- > 0) {
        		val = val * 10.0;
        	}
        }
        else if (sign == -1) {
        	while (e -- > 0) {
        		val = val / 10.0;
        	}
        }
    }

    return val;
}












