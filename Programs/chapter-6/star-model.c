#include <stdio.h>

int main() {
    int i, j;

    // আউটার  ফর লুপটি i এর মানের জন্য ঘুরছে
    for (i = 1; i <= 5; ++i) {

        // ইনার ফর লুপটি j এর মানের জন্য ঘুরছে
        for (j = 1; j <= i; ++j) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

