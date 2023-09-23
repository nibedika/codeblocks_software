#include<stdio.h>

int main()
{
    int i, n, ans;
    printf("Enter any number : ");
    scanf("%d", &n);

    for(i=1; i<=10; i++)
    {
        /*  যেই সংখ্যার নামটা প্রিন্ট হবে,
                        তার সাথে প্রতিবার i এর নতুন মান গুন্ হবে  */
        ans = n * i;
        printf("%d X %d = %d\n", n, i, ans);
    }
    return 0;
}

