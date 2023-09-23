#include<stdio.h>

int main()
{
    char x;
    printf("Enter a character : ");
    scanf("%c", &x); // একটি  বর্ণ  ইনপুট নেওয়া হলো

    // বর্ণটি ভাউয়েল নাকি কনসোনেন্ট তা চেক করা হবে
    if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
    {
       printf("This letter is vowel.");
    }
    else
    {
        printf("This letter is consonant.");
    }
    return 0;
}

