#include<stdio.h>
#include<stdlib.h>

int main()
{
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
        // ফাইল পয়েন্টার খোঁজে শুরুতে নিয়ে আসা
        rewind(fptr);

        // ফাইল পয়েন্টার-এর অবস্থান প্রিন্ট
        printf("%ld", ftell(fptr));
    }
    return 0;
}
