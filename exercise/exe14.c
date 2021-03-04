#include<stdio.h>

int main(void)
{
    char ch;
    while(!foef(stdin))
    {
        scanf("%c" , &ch);
        if(!feof(stdin))
        {
            printf("%c" , ch);
        }
    }
}
