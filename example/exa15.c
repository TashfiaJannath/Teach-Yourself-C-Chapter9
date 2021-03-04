#include<stdio.h>
#include<string.h>

int main(void)
{
    char str[10];
    int i;

    printf("enter a string");
    fgets(str , 10 , stdin);

    i=strlen(str)-1;
    if(str[i]=='\n')
    {
        str[i]='\0';
    }
    printf("this is your string %s" , str);
    return 0;
}
