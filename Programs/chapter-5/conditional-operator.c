#include<stdio.h>

int main()
{
    char x;
    printf("letter: ");
    scanf("%c", &x);

    // এখানে কন্ডিশনগুলো থেকে যেকোনো একটি সত্য হলে Vowel প্রিন্ট করবে অন্যথায় Consonant প্রিন্ট করবে
    (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' ||
	x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') ? printf("Vowel") : printf("Consonant");

    return 0;
}
