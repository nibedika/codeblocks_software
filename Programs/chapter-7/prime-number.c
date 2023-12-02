#include<stdio.h>
#include<stdbool.h>

// প্রাইম নম্বর চেক করার ফাংশন
bool isPrime(int n) {

    // 0 এবং 1 প্রাইম নম্বর না তাই, 1 এবং 1 এর ছোট নম্বর এর জন্য  false
    if (n <= 1) {
        return false;
    }

    /* 1 এর বড় সংখ্যাগুলোর জন্য যদি, ঐ সংখ্যা 2 থেকে পরপর ঐ
            সংখ্যার অর্ধেক মানের কোনো সংখ্যা দ্বারা নিঃশেষে বিভাজ্য হয়ে
            যায় তাহলে, বলা চলে সংখ্যাটি প্রাইম সংখ্যা না  */
    for (int i=2; i<=n/2; i++) {
        if (n%i == 0) {
            return false;
        }
    }

    /* এই ফাংশনের উপরের শর্তগুলো অনুযায়ী যদি সংখ্যাটি
            প্রাইম এর জন্য false না হয় তার মনে true অর্থাৎ
            সংখ্যাটি প্রাইম সংখ্যা হবে */
    return true;
}

int main() {
    int num;

    // সংখ্যা ইনপুট নেওয়া
    printf("Enter an integer: ");
    scanf("%d", &num);

    // isPrime() ফাংশনের রিটার্ন মানের উপর ভিত্তি করে প্রাইম সংখ্যা যাচাই করা
    if (isPrime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}
