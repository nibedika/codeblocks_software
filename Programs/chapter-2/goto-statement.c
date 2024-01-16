#include <stdio.h>

int main() {
    int count = 5;

    // লেবেল ডিক্লেয়ারেশন
    start_countdown:

    printf("%d\n", count);
    count--; // count-এর মান কমানো  1 করে (অপারেটর অধ্যায় দেখো)

    if (count >= 0) {
        // start_countdown লেবেল এ জাম্প করা
        goto start_countdown;
    }

    printf("Countdown Finished!");
    return 0;
}
