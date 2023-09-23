#include<stdio.h>

int main()
{
    int f[20], n, i;

    // সিরিজ এর প্রথম ২টি মান ইনিশিয়ালাইজ
    f[0] = 0;
    f[1] = 1;

    printf("Enter a number : ", n);
    scanf("%d", &n);

    // প্রথম ২টি মানের পরবর্তী মানগুলোর ক্যালকুলেশন
    for(i=2; i<n; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }

    // সিরিজের সকল মান প্রিন্ট
    printf("The fibonacci series is : ");
    for(i=0; i<n; i++)
    {
        printf(" %d ", f[i]);
    }
    return 0;
}

