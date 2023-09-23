#include<stdio.h>

// ফাংশন ডেফিনেশন
int sum()
{
    int a, b, s;
    printf("Enter two number : ");
    scanf("%d%d", &a, &b);
    s = a+b;
    printf("Summation value = %d", s);
    return s;
}
int main()
{
    return sum();  // ফাংশন  কল
}

