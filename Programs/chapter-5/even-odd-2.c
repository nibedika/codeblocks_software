#include<stdio.h>

int main()
{
    int num, l_digit;
    printf("Enter a number : ");
    scanf("%d", &num); // একটি সংখ্যা ইনপুট নেওয়া হলো

    // সংখ্যাটির সর্বশেষ অংক নির্ণয়
    l_digit = num % 10;

    // সর্বশেষ সংখ্যাটি 2, 4, 6, 8, 0  এর কোনোটি  কিনা চেক করা হবে
    if(l_digit == 2 || l_digit == 4 || l_digit == 6 || l_digit == 8 || l_digit == 0)
    {
       printf("The number is Even");
    }
    if(l_digit != 2 && l_digit != 4 && l_digit != 6 && l_digit != 8 && l_digit != 0)
    {
       printf("The number is Odd");
    }
    return 0;
}
