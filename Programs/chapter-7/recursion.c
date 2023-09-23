#include <stdio.h>

int sum(int n) {
    if (n != 0)
        return n + sum(n-1); // sum() ফাংশন নিজেকেই কল করছে
    else
        return n;
}

int main() {
   int n, result;
   scanf("%d", &n);
   result = sum(n);
   printf("Sum = %d", result);
   return 0;
}

