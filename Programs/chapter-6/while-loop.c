#include<stdio.h>

int main()
{
    int i, num;
    printf("Enter any number : ");
    scanf("%d", &num);

    i = 1; // i ডিক্লেয়ার

    while(i<=num) // কন্ডিশন সেট
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
        i++; // i এর মান বাড়ানো
    }
    return 0;
}
