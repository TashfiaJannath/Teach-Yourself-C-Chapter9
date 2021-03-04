#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc , char *argv[])
{
    FILE *from , *to;
    char ch , watch;

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

    if(argc==4 && !strcmp(argv[3], "watch"))
        watch =1;
    else
        watch = 0;

    while(ch=fgetc(from)!=EOF)
    {
        fputc(ch , to);
        if(watch)
            putchar(ch);
    }
    fclose(from);
    fclose(to);

    return 0 ;
}
