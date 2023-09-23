#include<stdio.h>

int main()
{
    float mark;
    printf("Enter mark : ");
    scanf("%f", &mark); // একটি  মার্ক  ইনপুট নেওয়া হলো

    // এই মার্কের জন্য গ্রেড নির্ধারণ করা হবে কন্ডিশন দ্বারা
    if(mark >=80 && mark <= 100)
    {
       printf("Your grade is : A+");
    }
    else if(mark >=70 && mark < 80)
    {
       printf("Your grade is : A");
    }
    else if(mark >=60 && mark < 70)
    {
       printf("Your grade is : A-");
    }
    else if(mark >=50 && mark < 60)
    {
       printf("Your grade is : B");
    }
    else if(mark >=40 && mark < 50)
    {
       printf("Your grade is : C");
    }
    else if(mark >=33 && mark < 40)
    {
       printf("Your grade is : D");
    }
    else if(mark >=0 && mark < 33)
    {
       printf("Your grade is : Fail");
    }
    else
    {
        printf("Incorrect mark.");
    }
    return 0;
}

