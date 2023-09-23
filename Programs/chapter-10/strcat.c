#include<stdio.h>
#include<string.h>

int main()
{
    char s1[20] = "Hello ";
    char s2[10] = "World!";
    strcat(s1, s2); //  s1 এবং s2 এর মানকে পাশাপাশি রাখা হচ্ছে
    printf("%s", s1);
    return 0;
}

