#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE* fptr;
	fptr = fopen("testfile.txt", "r");

	if(fptr == NULL)
    {
        printf("File not found !");
        exit(1);
    }
    else
    {
        // কার্সর এর বর্তমান অবস্থান খোঁজা
        fseek(fptr, 0, SEEK_CUR);

        // কার্সর এর অবস্থান প্রিন্ট
        printf("%ld", ftell(fptr));
    }
	return 0;
}

