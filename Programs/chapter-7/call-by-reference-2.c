#include <stdio.h>

// ভ্যারিয়েবল এর মান পরিবর্তন এর ফাংশন
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;

    // num1 ভ্যারিয়েবল এর জন্য মান ইনপুট নেওয়া
    printf("Enter value for num1: ");
    scanf("%d", &num1);

    // num2 ভ্যারিয়েবল এর জন্য মান ইনপুট নেওয়া
    printf("Enter value for num2: ");
    scanf("%d", &num2);

    // মান পরিবর্তন এর পূর্বে মানগুলো প্রিন্ট
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    // মান পরিবর্তন  এর জন্য ফাংশন কল
    swap(&num1, &num2);

    //  মান পরিবর্তন এর পর মানগুলো প্রিন্ট
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

