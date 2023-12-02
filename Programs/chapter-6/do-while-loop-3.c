#include <stdio.h>

int main() {
    int i = 0;

    // হুয়াইল লুপ
    printf("While Loop: ");
    while (i > 0) { // কন্ডিশন সেট
        printf("This should not be printed in a while loop!\n");
    }

    // ডো হুয়াইল লুপ
    printf("\nDo-While Loop: ");
    do {
        printf("This will be printed once in a do-while loop!\n");
    } while (i > 0); // কন্ডিশন সেট

    return 0;
}
