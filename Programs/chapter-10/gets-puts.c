#include<stdio.h>
#include<string.h>

int main()
{
    char ch[10];
    gets(ch); // scanf() এর মতো  কিন্তু ফরমেট স্পেসিফাই করতে হয় না
    puts(ch); // printf() এর মতো  কিন্তু ফরমেট স্পেসিফাই করতে হয় না
    return 0;
}

