#include <stdio.h>

int main() {
    float num1, num2, result;
    char op; // অপারেটর ভ্যারিয়েবল

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%f", &num2);

    // অপারেটর অনুযায়ী ক্যাল্কুলেশনের কাজ করা
    switch (op) {
        case '+':
            result = num1 + num2;
            printf("Result = %.2f\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result = %.2f\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result = %.2f\n", result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Zero Division Error.\n");
            } else {
                result = num1 / num2;
                printf("Result: %.2f\n", result);
            }
            break;
        default:
            printf("Error: Invalid operator\n");
    }
    return 0;
}

