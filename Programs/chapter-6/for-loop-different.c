#include<stdio.h>

int main()
{
    int i;
    i=1; // i এর মান নেওয়া

    // লিমিট সেট
    for(; i<=5; )
    {
	    // সংখ্যাটি প্রিন্ট করা
        printf("%d\n", i);

        // i এর মান বাড়ানো
        i++;
    }
    return 0;
}

