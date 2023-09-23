#include<stdio.h>
#include<string.h>

int main()
{
    char s1[20] = "Rahim";
    char s2[10] = "Karim";
    strcpy(s1, s2); // s2 এর মানকে s1 এর মাঝে কপি করা হচ্ছে
    printf("%s", s1);
    return 0;
}

