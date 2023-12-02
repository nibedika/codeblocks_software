#include <stdio.h>

int main() {
    int i;

    // ওয়ান ডাইমেনশনাল অ্যারেতে মান ইনপুট নেওয়া
    int num[] = {25, 18, 30, 15, 22, 10};

    // অ্যারেতে কতটি ভ্যালু ইনপুট নেওয়া হয়েছে তা নির্ণয় করা
    int size = sizeof(num) / sizeof(num[0]);
    printf("Size = %d\n", size);

    // ওয়ান ডাইমেনশনাল অ্যারের মান প্রিন্ট করা
    printf("Array = ");
    for(i=0; i<size; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");

    // অ্যারেতে থাকা ভ্যালুগুলোর এভারেজ মান নির্ণয়
    int sum = 0;
    for (i=0; i<size; i++) {
        sum += num[i];
    }
    double average = (double)sum / size;

    // এভারেজ মানটি প্রিন্ট
    printf("Average of the Array Elements = %.2lf\n", average);

    return 0;
}
