#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc , char *argv[])
{
    FILE *from , *to;
    char str[128];

    if(argc<3)
    {
        printf("usage: copy <source> <destination>\n");
        exit(1);
    }
    if((from = fopen(argv[1],"r"))==NULL)
    {
        printf("cannot open source file\n");
        exit(1);
    }
    if((to = fopen(argv[2],"w"))==NULL)
    {
        printf("cannot open destination file\n");
        exit(1);
    }


    while(!feof(from))
    {
        fgets(str,127,from);
        if(ferror(from))
        {
            printf("error to input\n");
            break;
        }
        if(!feof(from))
        {
            fputs(str,to);
        }
        if(ferror(to))
        {
            printf("error on output\n");
            break;
        }}

    if(fclose(from)==EOF)
    {
        printf("error closing source file");
        exit(1);
    }

    if(fclose(to)==EOF)
    {
        printf("error closing destination file");
        exit(1);
    }

    return 0 ;
}

