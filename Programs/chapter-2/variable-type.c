#include<stdio.h>

int temp1 = 20;

int test()
{
    int temp2 = 10;
    printf("\nTemp 1 Value = %d", temp1);
    printf("\nTemp 2 Value = %d", temp2);
    return 0;
}

int main()
{
    printf("\nTemp 1 Value = %d", temp1);
    test();
    return 0;
}
