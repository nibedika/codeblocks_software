#include<stdio.h>
#include<stdlib.h>

int main()
{
    // ফাইল পয়েন্টার ডিফাইন করা
	FILE* fptr;

	// ফাইল ওপেন করা
	fptr = fopen("testfile.txt", "r");

    // ফাইল ওপেন হয়েছে কিনা তা চেক করা
	if(fptr == NULL) {
		printf("Not Found!");
		exit(0);
	}
	else
    {
        printf("Opened!");
        exit(0);
    }
	return 0;
}

