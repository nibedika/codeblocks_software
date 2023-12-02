#include<stdio.h>
int main()
{
    float c, f;
    printf("Enter the temparature in Celsius : ");
    scanf("%f", &c);
    f = c * (9.0/5.0) + 32; // সেলসিয়াস থেকে ফারেনহাইটে রূপান্তরের সূত্র
    printf("\nTemperature in Fahrenheit = %f ", f);
    return 0;
}

