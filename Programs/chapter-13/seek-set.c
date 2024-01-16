#include<stdio.h>
#include<stdlib.h>

int main()
{
	// ফাইল পয়েন্টার ডিফাইন এবং ফাইল ওপেন করা
	FILE* fptr;
	fptr = fopen("testfile.txt", "r");

	// ফাইল ওপেন হয়েছে কিনা তা চেক করা
	if(fptr == NULL)
    {
        printf("File not found!");
        exit(1);
    }
    else
    {
        // ফাইল পয়েন্টার স্থানান্তর করা
        fseek(fptr, 10, SEEK_SET);

        // ফাইল পয়েন্টার-এর অবস্থান প্রিন্ট
        printf("%ld", ftell(fptr));
    }
    return 0;
}
