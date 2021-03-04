#include<stdio.h>

int main(void)
{
    if(rename("myfile.txt", "yourfile.txt"))
    {
        printf("rename failed\n");
    }
    else
    {
        printf("rename successful \n");
    }
    return 0;
}
