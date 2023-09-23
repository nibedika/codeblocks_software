#include<stdio.h>

int main()
{
    char x;
    printf("Enter a letter : ");
    scanf("%c", &x); // একটি  বর্ণ  ইনপুট নেওয়া হলো

    switch(x) // সুইচ ক্যাইসে x ভ্যারিয়েবলকে পাঠানো হলো
    {
        // কেইস দ্বারা x ভ্যারিয়েবলের মান চেক করা হবে
        case 'A':
            printf("This letter is vowel");
        break;

        case 'E':
            printf("This letter is vowel");
        break;

        case 'I':
            printf("This letter is vowel");
        break;

        case 'O':
            printf("This letter is vowel");
        break;

        case 'U':
            printf("This letter is vowel");
        break;

        case 'a':
            printf("This letter is vowel");
        break;

        case 'e':
            printf("This letter is vowel");
        break;

        case 'i':
            printf("This letter is vowel");
        break;

        case 'o':
            printf("This letter is vowel");
        break;

        case 'u':
            printf("This letter is vowel");
        break;

        // কোনো কেইস সত্য না হলে ডিফল্ট স্টেটমেন্ট প্রিন্ট হবে
        default:
            printf("This letter is consonant");
    }
    return 0;
}

