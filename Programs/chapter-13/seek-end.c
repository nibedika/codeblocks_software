#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE* fptr;
	fptr = fopen("testfile.txt", "r");

	if(fptr == NULL)
    {
        printf("File not found!");
        exit(1);
    }
    else
    {
        // কার্সরকে খোঁজে শেষে নিয়ে যাওয়া
        fseek(fptr, 0, SEEK_END);

        // কার্সর এর অবস্থান প্রিন্ট
        printf("%ld", ftell(fptr));
    }
	return 0;
}

