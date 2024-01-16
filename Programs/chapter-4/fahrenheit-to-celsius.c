#include<stdio.h>

int main()
{
    float c, f;
    printf("Enter the temperature in Fahrenheit : ");
    scanf("%f", &f);
    c = (f - 32) / 1.8; // এটা ফারেনহাইট থেকে সেলসিয়াসে রূপান্তরের সূত্র
    printf("\nTemperature in Celsius = %f ", c);
    return 0;
}
