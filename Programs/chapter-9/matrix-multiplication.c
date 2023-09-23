#include<stdio.h>

int main()
{
    int x[3][3], y[3][3], z[3][3], i, j, k;

    // x ম্যাট্রিক্সের মান ইনপুট নেওয়া
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%d", &x[i][j]);
        }
    }

    // y ম্যাট্রিক্সের মান ইনপুট নেওয়া
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%d", &y[i][j]);
        }
    }

    // x ম্যাট্রিক্সের মান প্রিন্ট
    printf("Matrix x = \n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d\t", x[i][j]);
        }
        printf("\n");
    }

    // y ম্যাট্রিক্সের মান প্রিন্ট
    printf("Matrix y = \n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d\t", y[i][j]);
        }
        printf("\n");
    }

    // x এবং y ম্যাট্রিক্সের মান গুন্
    printf("Output Matrix = \n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            z[i][j] = 0;
            for(k=0; k<3; k++)
            {
                z[i][j] += x[i][k] * y[k][j];
            }
            printf("%d\t", z[i][j]);
        }
        printf("\n");
    }

    return 0;
}

