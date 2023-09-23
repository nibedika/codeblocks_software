#include<stdio.h>
#include<stdlib.h>

int main()
{
    int r;

    // ফাইল পয়েন্টার ডিফাইন করা
    FILE *fptr;

    // read binary মোডে ফাইল ওপেন করা
    fptr = fopen("testfile.bin", "rb");

    // ফাইল ওপেন হয়েছে কিনা তা চেক করা
    if(fptr == NULL)
    {
        printf("File not found!");
        exit(1);
    }

    // বাইনারি ফাইল থেকে মান পড়া
    //fread(pointer,each_element_size, elements_no, file_pointer)
    fread(&r, sizeof(r), 1, fptr);

    printf("Result: %d\n", r);

    // ফাইল বন্ধ করা
    fclose(fptr);
    return 0;
}

