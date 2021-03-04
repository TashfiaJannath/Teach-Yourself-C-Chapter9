#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc , char *argv[])
{
    FILE *in, *out;
    long loc;
    char ch;
    if(argc!=3)
    {
        printf("usage: revcopy <source> <destination>\n");
        exit(1);
    }
    if((in = fopen(argv[1],"rb"))==NULL)
    {
        printf("cannot open input file\n");
        exit(1);
    }
    if((out = fopen(argv[2],"wb"))==NULL)
    {
        printf("cannot open output file\n");
        exit(1);
    }

    fseek(in , 0L , SEEK_END);
    loc - ftell(in);

    loc=loc-1;
    while(loc>= 0L)
    {
        fseek(in , loc , SEEK_SET);
        ch=fgetc(in);
        fputc(ch , out);
        loc--;
    }
    fclose(in);
    fclose(out);
    return 0 ;
}
