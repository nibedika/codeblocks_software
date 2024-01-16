#include<stdio.h>

int main()
{
    float a, b, c, s, area, perimeter;
    printf("Enter the three sides of triangle : ");
    scanf("%f%f%f", &a, &b, &c);

    s = (a+b+c)/2; // প্রথম এক্সপ্রেশন: সূত্র অনুযায়ী ২ দিয়ে ভাগ করে নিলাম তিনটা ভ্যারিয়েবলের যোগফলকে

    area = (s * (s-a) * (s-b) * (s-c)); // দ্বিতীয় এক্সপ্রেশন: ত্রিভুজের ক্ষেত্রফল নির্ণয়ের সূত্র

    perimeter = a+b+c;   // তৃতীয় এক্সপ্রেশন: ত্রিভুজের পরিধি নির্ণয়ের সূত্র

    printf("\nArea of the triangle is : %f\n", area);
    printf("\nPerimeter of the triangle is : %f\n", perimeter);
    return 0;
}
