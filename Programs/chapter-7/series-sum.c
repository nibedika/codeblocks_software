#include<stdio.h>

double series_sum(int num){
    double sum = 0.0;

    // ধারাটির যোগফল নির্ণয়
    for (int i=1; i<=num; i++) {
        sum += 1.0 / i;
    }

    // ধারাটির যোগফল প্রিন্ট
    printf("Sum of the harmonic series = %.2lf\n", sum);
}

int main() {
    int n;

    // n এর মান ইনপুট নেওয়া
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // series_sum() ফাংশনটি কল
    series_sum(n);

    return 0;
}

