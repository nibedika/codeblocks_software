#include<stdio.h>
#include<math.h>

// ফ্যাক্টোরিয়াল মান বার করার জন্য ফাংশন
double fact(int n) {
    if (n == 0 || n == 1) {
        return 1.0;
    } else {
        return n * fact(n - 2);
    }
}

// f(x) ধারাটির মান বার করার জন্য ফাংশন
double evaluateExp(double x, int terms) {
    double result = 0.0;

    for (int i=0; i<terms; i++) {
        result += pow(-1, i) * pow(x, 2*i + 1)/fact(2*i + 1);
        // printf("result = pow(-1, %d) * pow(%.1lf, 2*%d + 1)/fact(2*%d + 1) = %lf\n", i, x, i, i, result);
    }

    return result;
}

int main() {
    double x;
    int terms;

    //x এর মান ইনপুট নেওয়া
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // কত পর্যন্ত সংখ্যার পাওয়ার বার হবে সেটা ইনপুট নেওয়া
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    // আউটপুট প্রিন্ট করার জন্য result এর মাঝে f(x) ধারাটির মান রাখা
    double result = evaluateExp(x, terms);
    printf("\nf(x) = %lf\n", result);

    return 0;
}

