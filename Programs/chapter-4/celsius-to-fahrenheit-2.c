#include<stdio.h>

int main()
{
    float c, f;
    printf("Enter the temperature in Celsius : ");
    scanf("%f", &c);
    f = c * (9.0/5.0) + 32; // এখানে দেখ সূত্রটি একটু পাল্টে দেওয়া হয়েছে।
    printf("\nTemperature in Fahrenheit = %f ", f);
    return 0;
}
