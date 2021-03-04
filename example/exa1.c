#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    char str[80] = "This is a file system test.\n";
    FILE *fp;
    char *p,ch;
    int i;

    if((fp = fopen("myfile", "w"))==NULL)
    {
        printf("ERROR\n");
        exit(1);
    }

    p=str;
    while(*p)
    {
        if(fputc(*p , fp)==EOF)
        {
            printf("error\n");
            exit(1);
        }p++;
    }
    fclose(fp);

    if((fp = fopen("myfile", "r"))==NULL)
    {
        printf("ERROR\n");
        exit(1);
    }
    for(;;)
    {
        if((ch=fgetc(fp))==EOF)
        {
            break;
        }putchar(ch);
        return 0;
    }


}
