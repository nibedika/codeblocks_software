#include<stdio.h>
#include<math.h>

int main()
{
    int b, p, r;
    printf("Enter base and power : ");
    scanf("%d%d", &b, &p);
    r = pow(b, p); //  প্রথম আর্গুমেন্টি হলো বেস আর দ্বিতীয়টি পাওয়ার
    printf("Result = %d", r);
    return 0;
}

