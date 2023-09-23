#include<stdio.h>
#include<string.h>

int main()
{
    char str1[20], str2[20];
    gets(str1);

    // str1 এর মানকে str2 এর মাঝে কপি করা হচ্ছে
    strcpy(str2, str1);

    // str2 এ থাকা মানকে str1 এর উল্টো মানের সাথে তুলনা করা হচ্ছে
    if(strcmp(strrev(str1), str2) == 0)
    {
        printf("This word is palindrome.");
    }
    else
    {
        printf("This word is not palindrome.");
    }

    return 0;
}

