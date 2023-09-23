#include<stdio.h>

// গ্লোবাল ভ্যারিয়েবলের জন্য স্ট্যাটিক মেমোরি অ্যালোকেশন
int globalVar = 10;

void demoFunction() {
    // স্ট্যাটিক ভ্যারিয়েবলের জন্য স্ট্যাটিক মেমোরি অ্যালোকেশন
    static int staticVar = 20;

    printf("Global variable: %d\n", globalVar);
    printf("Static variable: %d\n", staticVar);
    staticVar += 5;
}

int main() {
    demoFunction();
    demoFunction();
    return 0;
}

