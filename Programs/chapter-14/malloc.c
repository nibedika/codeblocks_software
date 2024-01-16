#include<stdio.h>
#include<stdlib.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    /* নির্দিষ্ট সাইজের ইন্টিজার অ্যারের জন্য মেমোরি অ্যালোকেশন ।
            এখানে অ্যারের টাইপ int দেওয়ায় অ্যারের সাইজকে sizeof(int)
            দ্বারা গুন্ করে যেই পরিমান জায়গা হয় ততটুকু জায়গা মেমোরি থেকে
            নেওয়া হয়েছে malloc() ফাংশনের মাধ্যমে।  malloc() লাইব্রেরি
            ফাংশনটির রিটার্ন টাইপ void পয়েন্টার হওয়ায় এখানে কিন্তু এই
            ফাংশনটি ব্যবহার করার সময় int পয়েন্টার পেতে int * দ্বারা
    type cast (টাইপ পরিবর্তন করা) হয়েছে।  */
    int *dynamicArray = (int *)malloc(size * sizeof(int));

    // অ্যারেটি NULL হলে মেমোরি এলোকেশন ফেইল প্রিন্ট করা
    if (dynamicArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // size অনুযায়ী অ্যারেটিতে ভ্যালু ইনপুট নেওয়া
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &dynamicArray[i]);
    }

    // size অনুযায়ী অ্যারেটি প্রিন্ট করা
    printf("You entered the following integers:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

   /*অ্যারেটির মেমোরি ডি-অ্যালোকেশন অর্থাৎ অ্যারেটির জন্য নেওয়া মেমোরি স্পেস ছেড়ে দেওয়া  */
    free(dynamicArray);

    return 0;
}
