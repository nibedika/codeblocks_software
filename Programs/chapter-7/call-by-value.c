#include<stdio.h>

// ফাংশন ডেফিনেশন
int sum(int x, int y)
{
    int s;
    s = x+y;
    printf("Summation value = %d", s);
    return s;
}

int main()
{
    int a, b;
    printf("Enter two number : ");
    scanf("%d%d", &a, &b);

    sum(a, b); //  ফাংশন কলে ভ্যালু  পাঠানো আর্গুমেন্ট হিসেবে
    return 0;
}

