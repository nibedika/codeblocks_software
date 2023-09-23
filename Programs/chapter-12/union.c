#include<stdio.h>
#include<string.h>

// ইউনিয়ন ডিফাইন করা
union Student
{
    char name[50];
    char class_no[20];
    int roll;
    char subject[50];
    float mark;
    char grade[100];
};
union Student S; // ইউনিয়ন ইনস্ট্যান্স ডিফাইন

int main()
{
    // শিক্ষার্থীর তথ্য
    printf("Enter the information of a student: \n");

    scanf("%s", S.name);
    printf("Name: %s\n", S.name);

    scanf("%s", S.class_no);
    printf("Class: %s\n", S.class_no);

    scanf("%d", &S.roll);
    printf("Roll: %d\n", S.roll);

    scanf("%s", S.subject);
    printf("Subject: %s\n", S.subject);

    scanf("%f", &S.mark);
    printf("Mark: %.2f\n", S.mark);

    // শিক্ষার্থীর মার্ক থেকে গ্রেড বের করা
    if(S.mark >=80.00 && S.mark <= 100.00)
    {
        strcpy(S.grade, "A+");
    }
    else if(S.mark >=70.00 && S.mark < 80.00)
    {
        strcpy(S.grade, "A");
    }
    else if(S.mark >=60.00 && S.mark < 70.00)
    {
        strcpy(S.grade, "A-");
    }
    else if(S.mark >=50.00 && S.mark < 60.00)
    {
        strcpy(S.grade, "B");
    }
    else if(S.mark >=40.00 && S.mark < 50.00)
    {
        strcpy(S.grade, "C");
    }
    else if(S.mark >=33.00 && S.mark < 40.00)
    {
        strcpy(S.grade, "D");
    }
    else if(S.mark >=0.00 && S.mark < 33.00)
    {
        strcpy(S.grade, "Fail");
    }
    else
    {
        strcpy(S.grade, "Incorrect mark.");
    }

    // শিক্ষার্থীর গ্রেড  প্রিন্ট করা
    printf("Grade: %s", S.grade);
    return 0;
}
