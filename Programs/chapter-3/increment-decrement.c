#include <stdio.h>

int main() {
    int x = 5;
    printf("First x = %d\n", x);  //  x = 5 প্রিন্ট করবে

    int y = x++ * 2;
    printf("Second x = %d\n", x);
    printf("Value of y =  %d, and x = %d\n", y, x);  /* y =  10 ও x = 6 প্রিন্ট করবে */

    x = 5; // x-এর মান আবার 5 করলাম
    y = ++x * 2;

    printf("Third x = %d\n", x);
    printf("Value of y =  %d, and x = %d\n", y, x); /* y =  12 ও x = 6 প্রিন্ট করবে */
    return 0;
}
