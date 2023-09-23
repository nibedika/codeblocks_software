#include<stdio.h>

int main()
{
    int num;
    printf("Enter a number : ");
    scanf("%d", &num); // একটি সংখ্যা ইনপুট নেওয়া হলো

    // সংখ্যাটি ২ দ্বারা নিঃশেষে বিভাজ্য কিনা চেক করা হবে
    if(num%2 == 0)
    {
       printf("The number is Even");
    }
    if(num%2 != 0)
    {
       printf("The number is Odd");
    }
    return 0;
}

