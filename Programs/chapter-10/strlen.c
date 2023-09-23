#include<stdio.h>
#include<string.h>

int main()
{
    char pass[10];
    int n;
    printf("Enter password: ", n);
    scanf("%s", pass);
    n = strlen(pass); // ভ্যারিয়েবলের ক্যারেক্টার সংখ্যা বার করবে

    if(n == 6)
    {
        printf("Correct length", n);
    }
    else
    {
        printf("Incorrect length", n);
    }
    return 0;
}

