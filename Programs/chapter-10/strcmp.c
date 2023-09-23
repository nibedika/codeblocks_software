#include<stdio.h>
#include<string.h>

int main()
{
    char s1[10] = "Rahim";
    char s2[10] = "Karim";
    char s3[10] = "Rahim";

    // s1 এবং  s2 এর মান তুলনা করা হচ্ছে
    printf("Comparing s1 and s2 = %d\n", strcmp(s1, s2));

    // s1 এবং  s3 এর মান তুলনা করা হচ্ছে
    printf("Comparing s1 and s3 = %d", strcmp(s1, s3));

    return 0;
}

