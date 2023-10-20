#include<stdio.h>

int main()
{
    int num, temp_num1;
    float temp_num2;
    printf("Enter a number : ");
    scanf("%d", &num); // একটি সংখ্যা ইনপুট নেওয়া হলো

    // temp_num1 ভ্যারিয়েবল এ ভাগফল আকারে শুধু পূর্ণ সংখ্যা রাখা হয়েছে
    temp_num1 = num / 2;
    printf("temp_num1 = %d\n", temp_num1);

    // temp_num2 ভ্যারিয়েবল এ ভাগফল আকারে সম্পূর্ণ বাস্তব সংখ্যাটি রাখা হয়েছে
    temp_num2 = (float)num / 2;
    printf("temp_num2 = %f\n", temp_num2);

    // ২টি সংখ্যাকে তুলনা করা
    if(temp_num2 == temp_num1)
    {
       printf("The number is Even");
    }
    if(temp_num2 > temp_num1)
    {
       printf("The number is Odd");
    }
    return 0;
}
