#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc , char *argv[])
{
    FILE *f1 , *f2 ,*temp;
    char ch;

    if(argc!=3)
    {
        printf("usage: exchange <f1> <f2>\n");
        exit(1);
    }
    if((f1 = fopen(argv[1],"rb"))==NULL)
    {
        printf("cannot open 1st file\n");
        exit(1);
    }
    if((f2 = fopen(argv[2],"rb"))==NULL)
    {
        printf("cannot open 2nd file\n");
        exit(1);
    }
    if((temp = fopen("temp.tmp","wb"))==NULL)
    {
        printf("cannot open temporary file\n");
        exit(1);
    }

    while(!feof(f1))
    {
        ch = fgetc(f1);
        if(!feof(f1))
            fputc(ch , temp);
    }
    fclose(f1);

    if((f1 = fopen(argv[1],"wb"))==NULL)
    {
        printf("cannot open 1st file\n");
        exit(1);
    }
    while(!feof(f2))
    {
        ch = fgetc(f2);
        if(!feof(f2))
            fputc(ch , f1);
    }
    fclose(f2);
    fclose(temp);

    if((f2 = fopen(argv[2],"wb"))==NULL)
    {
        printf("cannot open 2nd file\n");
        exit(1);
    }
    if((temp = fopen("temp.tmp","rb"))==NULL)
    {
        printf("cannot open temporary file\n");
        exit(1);
    }

    while(!feof(temp))
    {
        ch = fgetc(temp);
        if(!feof(temp))
            fputc(ch , f2);
    }

    fclose(f1);
    fclose(f2);
    fclose(temp);
    return 0 ;
}





