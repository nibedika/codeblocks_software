#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // 0 দ্বারা ইনিশিয়ালাইজ করে নির্দিষ্ট সাইজের ইন্টিজার অ্যারে এর জন্য মেমোরি অ্যালোকেশন
    int *dynamicArray = (int *)calloc(size, sizeof(int));

    if (dynamicArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("You entered %d integers, which are initialized to zero:\n", size);
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // মেমোরি ডি-অ্যালোকেশন
    free(dynamicArray);

    return 0;
}

