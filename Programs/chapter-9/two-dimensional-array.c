#include<stdio.h>

int main()
{
    // টু ডাইমেনশনাল অ্যারে ইনিশিয়ালাইজেশন
    int num[3][2] = {{3, 2}, {4, 8}, {8, 9}};
    int i, j;

    // প্রিন্টিং অ্যারে এলিমেন্টস/ভ্যালুজ
    for(i=0; i<=2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d\t", num[i][j]);
        }
        printf("\n");
    }
    return 0;
}
