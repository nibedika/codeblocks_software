// সি প্রোগ্রাম এর সাহায্যে স্টুডেন্ট ম্যানেজমেন্ট সিস্টেম
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

// শিক্ষার্থীর সংখ্যা গণনার জন্য ভ্যারিয়েবল
int i = 0;

// শিক্ষার্থীর তথ্য নেওয়ার জন্য স্ট্রাকচার
struct sinfo {
	char fname[50];
	char lname[50];
	int roll;
	float gpa;
	int sub_code[20];
} st[100];

// শিক্ষার্থীর তথ্য নেওয়া
void add_student()
{
	printf("Add Students Details:-\n");

	printf("\nEnter First Name: ");
	scanf("%s", st[i].fname);

	printf("\nEnter Last Name: ");
	scanf("%s", st[i].lname);

	printf("\nEnter Roll Number: ");
	scanf("%d", &st[i].roll);

	printf("\nEnter GPA: ");
	scanf("%f", &st[i].gpa);

	printf("\nEnter Subject Code: ");
	for (int j = 0; j < 5; j++) {
		scanf("%d", &st[i].sub_code[j]);
	}
	i = i + 1;
}

// শিক্ষার্থীর তথ্য আপডেট
void update_student()
{
	printf("Enter Roll Number: ");
	long int x;
	scanf("%ld", &x);

	for (int j = 0; j < x; j++) {
		if (st[j].roll == x) {
            printf("1 = first name, 2 = last name, 3 = roll, 4 = GPA, 5 = subject\n");
			int z;
			scanf("%d", &z);

			switch(z) {
                case 1:
                    printf("Enter the new first name: ");
                    scanf("%s", st[j].fname);
                    break;
                case 2:
                    printf("\nEnter the new last name: ");
                    scanf("%s", st[j].lname);
                    break;
                case 3:
                    printf("\nEnter the new roll: ");
                    scanf("%d", &st[j].roll);
                    break;
                case 4:
                    printf("\nEnter the new GPA: ");
                    scanf("%f", &st[j].gpa);
                    break;
                case 5:
                    printf("\nEnter the new subjects: ");
                    scanf("%d%d%d%d%d", &st[j].sub_code[0], &st[j].sub_code[1],
                          &st[j].sub_code[2], &st[j].sub_code[3], &st[j].sub_code[4]);
                    break;
			}
			printf("Student info updated successfully! \n");
		}
	}
}

// শিক্ষার্থীর তথ্য ডিলিট
void delete_student()
{
	int a;
	printf("Enter Roll Number: ");
	scanf("%d", &a);
	for (int j = 1; j <= i; j++) {
		if (a == st[j].roll) {
			for (int k = j; k < 49; k++)
				st[k] = st[k + 1];
			i--;
		}
	}
	printf("Student info deleted successfully!\n");
}

// শিক্ষার্থীর তথ্য দেখানো
void student_details(int f)
{
	printf("The Students Details:- \n");
    printf("The first name is: %s\n", st[f].fname);
    printf("The last name is: %s\n", st[f].lname);
    printf("The roll number is: %d\n ", st[f].roll);
    printf("The GPA is: %f\n", st[f].gpa);
}

// শিক্ষার্থীর সংখ্যা বার করা
void count_student()
{
	printf("The total number of student = %d\n", i);
	printf("Student vacancy = %d\n", 100-i);
}

// রোল দ্বারা শিক্ষার্থীর তথ্য বার করা
void find_roll()
{
	int x;
	printf("Enter Roll Number: ");
	scanf("%d", &x);

	for (int j = 1; j <= i; j++) {
		if (x == st[i].roll) {
            student_details(i);
		}
		for (int j = 0; j < 5; j++) {
			printf("The subjects are: %d\n", st[i].sub_code[j]);
		}
		break;
	}
}

// প্রথম নাম দ্বারা শিক্ষার্থীর তথ্য বার করা
void find_first_name()
{
	char a[50];
	printf("Enter First Name: ");
	scanf("%s", a);
	int c = 0;

	for (int j = 1; j <= i; j++) {
		if (!strcmp(st[j].fname, a)) {

			student_details(i);

			for (int j = 0; j < 5; j++) {
                printf("The subjects are: %d\n", st[i].sub_code[j]);
            }
            break;
			c = 1;
		}
		else
        {
            printf("The student not found!\n");
        }
	}
}

// বিষয় দ্বারা শিক্ষার্থীর তথ্য বার করা
void find_subject()
{
	int id;
	printf("Enter Subject Code: \n");
	scanf("%d", &id);
	int c = 0;

	for (int j = 1; j <= i; j++) {
		for (int d = 0; d < 5; d++) {
			if (id == st[j].sub_code[d]) {

				student_details(i);
				c = 1;
				break;
			}
			else
            {
                printf("The student not found!\n");
            }
		}
	}
}

// মেইন ফাংশন
void main()
{
	int choice, count;
	while(i = 1) {
		printf("1 = add, 2 = update, 3 = delete, 4 = count, 5 = roll, 6 = name, 7 = subject, 8 = quit\n");
		printf("Enter Choice: ");
		scanf("%d", &choice);

		switch(choice) {
            case 1:
                add_student();
                break;
            case 2:
                update_student();
                break;
            case 3:
                delete_student();
                break;
            case 4:
                count_student();
                break;
            case 5:
                find_roll();
                break;
            case 6:
                find_first_name();
                break;
            case 7:
                find_subject();
                break;
            case 8:
                exit(0);
                break;
		}
	}
}
