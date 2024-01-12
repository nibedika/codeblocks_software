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
} st[100]; //st হলো স্ট্রাকচারটির ইনস্ট্যান্স

// শিক্ষার্থীর তথ্য নেওয়া
void add_student()
{
	printf("Add Students Details:-\n");

    // প্রথম নাম ইনপুট নেওয়া
	printf("\nEnter First Name: ");
	scanf("%s", st[i].fname);

    // শেষ  নাম ইনপুট নেওয়া
	printf("\nEnter Last Name: ");
	scanf("%s", st[i].lname);

    // রোল ইনপুট নেওয়া
	printf("\nEnter Roll Number: ");
	scanf("%d", &st[i].roll);

    // জিপিএ ইনপুট নেওয়া
	printf("\nEnter GPA: ");
	scanf("%f", &st[i].gpa);

    // sub_code অ্যারেতে একাধিক সাবজেক্ট কোড নেওয়া
	printf("\nEnter Subject Code: ");
	for (int j = 0; j < 5; j++) {
		scanf("%d", &st[i].sub_code[j]);
	}
	i = i + 1;
}

// শিক্ষার্থীর তথ্য আপডেট
void update_student()
{
    // রোল ইনপুট নেওয়া
	printf("Enter Roll Number: ");
	long int x;
	scanf("%d", &x);

	for (int j = 0; j < x; j++) {
        // রোলটি কোন শিক্ষার্থীর তা মিলানো
	    if (x == st[j].roll) {

	        // শিক্ষার্থীর যে তথ্য পরিবর্তন করতে হবে তা সিলেক্ট করা
            printf("1 = first name, 2 = last name, 3 = roll, 4 = GPA, 5 = subject\n");
			int z;
			scanf("%d", &z);

            // শিক্ষার্থীর যে তথ্য পরিবর্তন করতে হবে তা ইনপুট নেওয়া
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
                    scanf("%d%d%d%d%d", &st[j].sub_code[0],
					&st[j].sub_code[1], &st[j].sub_code[2],
                    &st[j].sub_code[3], &st[j].sub_code[4]);
                    break;
			}
			printf("Student info updated successfully! \n");
		}
	}
}

// শিক্ষার্থীর তথ্য ডিলিট
void delete_student()
{
    // রোল ইনপুট নেওয়া
	int x;
	printf("Enter Roll Number: ");
	scanf("%d", &x);

	// রোল অনুযায়ী তথ্য মুছে ফেলা
	for (int j = 1; j <= i; j++) {
		if (x == st[j].roll) {
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
    // রোল ইনপুট নেওয়া
	int x;
	printf("Enter Roll Number: ");
	scanf("%d", &x);
	int found = 0;

	for (int j = 0; j < i; j++) {
        // রোল এর সাথে মিলিয়ে শিক্ষার্থীর তথ্য প্রিন্ট করা
		if (x == st[j].roll) {
            student_details(j);

            // শিক্ষার্থীর সাবজেক্ট কোডগুলো প্রিন্ট করা
            for (int k = 0; k < 5; k++) {
                printf("The subjects are: %d\n", st[j].sub_code[k]);
            }

            // তথ্য খুঁজে পেলে স্টেটাস পরিবর্তন করা
            found = 1;
            break;
		}
	}

    // তথ্য খুঁজে না পেলে মেসেজে প্রিন্ট করা
	if (!found) {
        printf("Student not found!\n");
    }
}

// প্রথম নাম দ্বারা শিক্ষার্থীর তথ্য বার করা
void find_first_name()
{
    // প্রথম নাম ইনপুট নেওয়া
	char a[50];
	printf("Enter First Name: ");
	scanf("%s", a);
	int found = 0;

    // প্রথম নাম দ্বারা শিক্ষার্থী খোঁজা
	for (int j = 0; j < i; j++) {
		if (!strcmp(st[j].fname, a)) {

            // প্রথম নাম এর সাথে মিলিয়ে শিক্ষার্থীর তথ্য প্রিন্ট করা
			student_details(j);

            // শিক্ষার্থীর সাবজেক্ট কোডগুলো প্রিন্ট করা
            for (int k = 0; k < 5; k++) {
                printf("The subjects are: %d\n", st[j].sub_code[k]);
            }

            // তথ্য খুঁজে পেলে স্টেটাস পরিবর্তন করা
            found = 1;
            break;
		}
	}

    // তথ্য খুঁজে না পেলে মেসেজে প্রিন্ট করা
	if (!found) {
        printf("Student not found!\n");
    }
}

// বিষয় দ্বারা শিক্ষার্থীর তথ্য বার করা
void find_subject()
{
    // বিষয় ইনপুট নেওয়া
	int c;
	printf("Enter Subject Code: ");
	scanf("%d", &c);
	int found = 0;

    // বিষয় দ্বারা শিক্ষার্থী খোঁজা
	for (int j = 0; j < i; j++) {
		for (int k = 0; k < 5; k++) {
			if (c == st[j].sub_code[k]) {

                // বিষয় এর সাথে মিলিয়ে শিক্ষার্থীর তথ্য প্রিন্ট করা
				student_details(j);

                // তথ্য খুঁজে পেলে স্টেটাস পরিবর্তন করা
				found = 1;
				break;
			}
		}
	}

    // তথ্য খুঁজে না পেলে মেসেজে প্রিন্ট করা
	if (!found) {
        printf("Student not found!\n");
    }
}

// মেইন ফাংশন
void main()
{
	int choice;

	while(i < 100) {
        // প্রোগ্রামটি দ্বারা কি কাজ করবো তা সিলেক্ট করা
		printf("1 = add, 2 = update, 3 = delete, 4 = count, 5 = roll, 6 = name, 7 = subject, 8 = quit\n");
		printf("Enter Choice: ");
		//scanf("%d", &choice);

		// ইনপুটটি ইন্টিজার নেওয়া হয়েছে কিনা চেক করে ইনপুট নেওয়া
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a valid option.\n");
            while (getchar() != '\n'); // ইনপুট ইন্টিজার না হলে ইনপুট ক্লিয়ার করে দেওয়া
            continue;
        }

        // সঠিক অপসন সিলেক্ট না করলে আবার লুপ এর শুরুতে ফিরে যাওয়ার জন্য
		if (choice < 1 || choice > 8) {
            printf("Select correct option!\n");
            continue;
        }

        // সিলেক্ট করা কাজ অনুযায়ী ফাংশন নির্বাচন
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
