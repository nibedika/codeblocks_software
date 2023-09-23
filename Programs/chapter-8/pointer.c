#include<stdio.h>

int main()
{
    int n = 20;
    int *p; // পয়েন্টার ভ্যারিয়েবল ডিক্লেয়ারেশন
    p = &n; // পয়েন্টার ভ্যারিয়েবল দ্বারা অন্য ভ্যারিয়েবলের জায়গা স্টোর
    printf("Address = %d\n", p);
    printf("Value = %d", *p);
    return 0;
}
