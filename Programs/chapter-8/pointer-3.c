#include <stdio.h>

int main() {

    // ২টি ভ্যারিয়েবলের মান নেওয়া
    int num1 = 10;
    int num2 = 20;


    /* পরিবর্তনের পূর্বে মানগুলোকে একবার ভ্যারিয়েবল এর নাম
           এবং অন্যবার পয়েন্টার দ্বারা প্রিন্ট করা */
    printf("Values using variables: num1 = %d, num2 = %d\n", num1, num2);

    // পয়েন্টার দ্বারা মানগুলুর পরিবর্তন
    num1 = 100;
    num2 = 200;

    /* পরিবর্তনের পর মানগুলোকে একবার ভ্যারিয়েবল এর নাম
           এবং অন্যবার পয়েন্টার দ্বারা প্রিন্ট করা */
    printf("Modified values using variables: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

