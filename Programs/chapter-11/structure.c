#include<stdio.h>
#include<string.h>

// স্ট্রাকচার ডিফাইন করা
struct Student
{
    char name[50];
    char class_no[20];
    int roll;
    char subject[50];
    float mark;
    char grade[100];
};
struct Student S; // স্ট্রাকচার ইনস্ট্যান্স ডিফাইন

int main()
{
    // শিক্ষার্থীর তথ্য নেওয়া
    printf("Enter the information of a student: ");
    scanf("%s%s%d%s%f", S.name, S.class_no, &S.roll, S.subject, &S.mark);

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

    // শিক্ষার্থীর তথ্য  প্রিন্ট করা
    printf("Result = \nName: %s\nClass: %s\nRoll: %d\nSubject: %s\nMark: %.2f\nGrade: %s",
           S.name, S.class_no, S.roll, S.subject, S.mark, S.grade);
    return 0;
}

