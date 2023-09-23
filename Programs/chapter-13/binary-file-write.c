#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a, b, r;

    // ফাইল পয়েন্টার ডিফাইন করা
    FILE *fptr;

    // write binary মোডে ফাইল ওপেন করা
    fptr = fopen("testfile.bin", "wb");

    // ফাইল ওপেন হয়েছে কিনা তা চেক করা
    if(fptr == NULL)
    {
        printf("File not found!");
        exit(1);
    }

    // ২টি সংখ্যা যোগ করা
    printf("Enter two value: ");
    scanf("%d%d", &a, &b);
    r = a+b;

    // বাইনারি ফাইলে যোগফল লেখা
    //fwrite(pointer, each_element_size, elements_no, file_pointer)
    fwrite(&r, sizeof(r), 1, fptr);

    // ফাইল বন্ধ করা
    fclose(fptr);
    return 0;
}

