#include <stdio.h>

void modifyValue(int *x) {
    /* main() ফাংশনের মাঝে modifyValue() ফাংশনটি
            কল করার সময় আর্গুমেন্টে মান পাঠানো হয়েছিল 5 কিন্তু ভ্যালু
            প্যারামিটার দ্বারা রিসিভ করার পর তা modifyValue()
            ফাংশনের মাঝে পরিবর্তন করে 10 করা হয়েছে। */
    *x = 10;
    printf("%d", *x);
}

int main() {
    int num = 5;
    modifyValue(&num);

    // এখন ভ্যালু 10
    return 0;
}
