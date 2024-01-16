#include<stdio.h>
#include<stdlib.h>

int main()
{
    // ফাইল পয়েন্টার ডিফাইন করা
	FILE* fptr;

	// ফাইল ওপেন করা
	fptr = fopen("testfile.txt", "r");

    // ফাইল ওপেন হয়েছে কিনা তা চেক করা এবং ওপেন না হয়ে থাকলে প্রসেস থেকে এক্সিট করা
	if(fptr == NULL) {
		printf("Not Found!");
		exit(0); /* এক্সিট stdlib.h এর ফাংশন যা কোনো প্রোগ্রামকে আর আগাতে দেয় না */
	}
	else
    {
        printf("Opened!");
        exit(0);
    }
	return 0;
}
