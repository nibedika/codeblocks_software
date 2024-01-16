#include<stdio.h>

int main()
{
    int year;
    printf("Enter a year : ");
    scanf("%d", &year);

    // যদি এই কন্ডিশনগুলো থেকে যেকোনো একটি সত্য হয় তবে লিপ ইয়ার
    if(year%400 == 0 || year%100 == 0 || year%4 == 0)
    {
       printf("This year is leap year.");
    }
    // অন্যথায় লিপ ইয়ার নয়
    else
    {
        printf("This year is not a leap year.");
    }
    return 0;
}
