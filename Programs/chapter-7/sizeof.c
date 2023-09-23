#include<stdio.h>

int main()
{
    int space, num;
    printf("Enter a number : ");
    scanf("%d", &num);
    space = sizeof(num); // ভ্যারিয়েবলের মেমোরি স্পেস বার করার ফাংশন
    printf("This number takes(Byte) = %d", space);
    return 0;
}
