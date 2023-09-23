#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
   char name[100];

   // ফাইল পয়েন্টার ডিফাইন করা
   FILE *fptr;

   // write মোডে ফাইল ওপেন করা
   fptr = fopen("testfile.txt", "w");

   // ফাইল ওপেন হয়েছে কিনা তা চেক করা
   if(fptr == NULL)
   {
      printf("File not found!");
      exit(1);
   }
   else
   {
       puts("Enter your name: ");
       gets(name);

       // ফাইলে লেখা
       fprintf(fptr, "%s", name);

       // ফাইল বন্ধ করা
       fclose(fptr);
   }
   return 0;
}

