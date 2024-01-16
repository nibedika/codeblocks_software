#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;

    printf("Enter the initial size of the array: ");
    scanf("%d", &size);

    // নির্দিষ্ট সাইজের ইন্টিজার অ্যারের জন্য মেমোরি অ্যালোকেশন
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

    // অ্যারের সাইজ পরিবর্তন
    int newSize;
    printf("Enter the new size of the array: ");
    scanf("%d", &newSize);

    // নতুন সাইজের ইন্টিজার অ্যারের জন্য মেমোরি অ্যালোকেশন
    int *resizedArray = (int *)realloc(dynamicArray, newSize * sizeof(int));

    // নতুন সাইজের অ্যারেটি NULL হলে মেমোরি এলোকেশন ফেইল প্রিন্ট করা
    if (resizedArray == NULL) {
        printf("Memory reallocation failed.\n");
        free(dynamicArray);
        return 1;
    }

    // নতুন size অনুযায়ী অ্যারেটিতে ভ্যালু ইনপুট নেওয়া
    printf("Enter %d additional integers:\n", newSize - size);
    for (int i = size; i < newSize; i++) {
        scanf("%d", &resizedArray[i]);
    }

    // নতুন size অনুযায়ী অ্যারেটি প্রিন্ট করা
    printf("You entered the following integers (after resizing):\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", resizedArray[i]);
    }
    printf("\n");

    // মেমোরি ডি-অ্যালোকেশন (নোট: resizedArray এখন ভ্যালিড)
    free(resizedArray);

    return 0;
}
