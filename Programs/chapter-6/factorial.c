#include<stdio.h>
int main()
{
    int i, n, f=1;
    printf("Enter any number : ");
    scanf("%d", &n);

    if(n==0)
    {
        // কারণ 0! এর মান 1 হয়
        printf("Factorial value = 1");
    }
    else
    {
        for(i=1; i<=n; i++)
        {
            // প্রতিবার i এর নতুন মান এর সাথে পূর্বের f এর মান গুন্
            f = f * i;
        }
        printf("Factorial value = %d", f);
    }
    return 0;
}

