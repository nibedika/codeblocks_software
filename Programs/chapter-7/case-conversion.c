#include<stdio.h>
#include<ctype.h>

int main()
{
    char x;
    printf("Enter a letter : ");
    scanf("%c", &x);

    if(isupper(x)) // ইনপুট বড় হাতের কিনা চেক করবে
    {
        // বড় হাতের হলে ছোট হাতের বর্ণে পরিবর্তন করে প্রিন্ট করবে
        printf("%c", tolower(x));
    }
    if(islower(x)) // ইনপুট ছোট হাতের কিনা চেক করবে
    {
        // ছোট হাতের হলে বড় হাতের বর্ণে পরিবর্তন করে প্রিন্ট করবে
        printf("%c", toupper(x));
    }
    return 0;
}
