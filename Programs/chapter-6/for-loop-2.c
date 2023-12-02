#include<stdio.h>

int main()
{
    int i, num;
    printf("Enter any number : ");
    scanf("%d", &num);

    // i ডিক্লেয়ার, লিমিট সেট  এবং i এর মান বাড়ানো
    for(i = 1; i<=num; i++)
    {
        //  কন্ডিশন চেক
        if(i%2 == 0)
        {
            printf("%d is even\n", i);
        }
        else
        {
            printf("%d is odd\n", i);
        }
    }
    return 0;
}

