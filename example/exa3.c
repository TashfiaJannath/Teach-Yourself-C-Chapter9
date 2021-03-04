#include<stdio.h>
#include<stdlib.h>

int main(int argc , char *argv[])
{
    FILE *from , *to;
    char ch;

    if(argc!=3)
    {
        printf("usage: copy <source> <destination>\n");
        exit(1);
    }
    if((from = fopen(argv[1],"rb"))==NULL)
    {
        printf("cannot open source file\n");
        exit(1);
    }
    if((to = fopen(argv[2],"wb"))==NULL)
    {
        printf("cannot open destination file\n");
        exit(1);
    }
    while(!feof(from))
    {
        ch =fgetc(from);
        if(ferror(from))
        {
            printf("error reading source file\n");
            exit(1);
        }
        if(!feof(from))
            fputc(ch,to);
        if(ferror(to))
        {
            printf("error writing destination file.\n");
            exit(1);
        }
    }
    if(fclose(from)==EOF)
    {
        printf("error closing destination file\n");
        exit(1);
    }
    return 0;
}
