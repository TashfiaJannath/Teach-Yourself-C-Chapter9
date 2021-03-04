#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(void)
{
    char fname[80];
    printf("enter the name of file to erase");
    gets(fname);
    printf("are you sure?");
    if(toupper(getchar())=='Y')
        if(remove(fname))
            printf("\n file not found or write protected");

    return 0 ;
}
