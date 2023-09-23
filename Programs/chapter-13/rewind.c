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
        // কার্সরকে খোঁজে  শুরুতে নিয়ে আসা
        rewind(fptr);
    }
	return 0;
}

