#include <stdio.h>
int main() {
    float pi = 3.14159, area;   // pi ভ্যারিয়েবল ইনিশিয়ালাইজেশন
    int r;   // r ভ্যারিয়েবল  ডিক্লেয়ারেশন

    printf("Enter radius : ");
    scanf("%d", &r);   // r ভ্যারিয়েবলের মান ইনপুট নেওয়া
    area = pi*(r*r);
    printf("Area of circle = %f", area);
    return 0;
}

