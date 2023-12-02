#include <stdio.h>

int main() {

    // ২টি ভ্যারিয়েবলের মান নেওয়া
    int num1 = 10;
    int num2 = 20;

    // ২টি পয়েন্টার ভ্যারিয়েবল ডিক্লেয়ারেশন
    int *ptr1, *ptr2;

    /* num1 এবং num2 ভ্যারিয়েবল এর মেমোরি লোকেশন
    &num1 এবং &num2 কে ক্রমান্বয়ে ptr1 এবং ptr1
           পয়েন্টার ভ্যারিয়েবল এর মাঝে রাখা  */
    ptr1 = &num1;
    ptr2 = &num2;

    /* পরিবর্তনের পূর্বে মানগুলোকে একবার ভ্যারিয়েবল এর নাম
           এবং অন্যবার পয়েন্টার দ্বারা প্রিন্ট করা */
    printf("Values using variables: num1 = %d, num2 = %d\n", num1, num2);
    printf("Values using pointers: *ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2);

    // পয়েন্টার দ্বারা মানগুলুর পরিবর্তন
    *ptr1 = 100;
    *ptr2 = 200;

    /* পরিবর্তনের পর মানগুলোকে একবার ভ্যারিয়েবল এর নাম
           এবং অন্যবার পয়েন্টার দ্বারা প্রিন্ট করা */
    printf("Modified values using variables: num1 = %d, num2 = %d\n", num1, num2);
    printf("Modified values using pointers: *ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2);

    return 0;
}

