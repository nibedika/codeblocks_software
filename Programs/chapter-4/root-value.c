#include<stdio.h>
#include<math.h> //এটা দিয়েছি sqrt() ফাংশন ব্যবহার করার জন্য

int main()
{
    int n;
    float s;
    printf("Enter any number : ");
    scanf("%d",&n);

    // বর্গমূল নির্ণয় করার ফাংশন sqrt() দ্বারা এক্সপ্রেশন তৈরী
    s = sqrt(n);

    printf("The square root of n is : %f",s);
    return 0;
}
