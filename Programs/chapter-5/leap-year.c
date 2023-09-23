#include<stdio.h>

int main()
{
    int year;
    printf("Enter a year : ");
    scanf("%d", &year); // একটি  সাল  ইনপুট নেওয়া হলো

    // সালটি লিপ ইয়ার কিনা চেক করা হবে
    if(year%400 == 0 || year%100 == 0 || year%4 == 0)
    {
       printf("This year is leap year.");
    }
    return 0;
}

