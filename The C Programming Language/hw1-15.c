#include <stdio.h>

/* C hw 1.15 */

void celsiusToFahrenheit();

int main()

{
    celsiusToFahrenheit();
}   

void celsiusToFahrenheit() {
    /* print Celsius-Fahrenheit table， from C -17.8 to C 148.9*/

    float fahr, celsius;
    float lower, upper, step;

    lower = -17.8;
    upper = 148.9;
    step = (upper - lower) / 15.0; // step size

    celsius = lower;

    while (celsius <= upper) {
        fahr = celsius / 5.0 * 9.0 + 32.0;
        printf("%6.1f %3.0f\n", celsius, fahr);
        celsius += step;
    }
}