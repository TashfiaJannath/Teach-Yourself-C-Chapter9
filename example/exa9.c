#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc , char *argv[])
{
    FILE *fp;
    long loc;
    if(argc!=2)
    {
        printf("file name missing\n");
        exit(1);
    }
    if((fp = fopen(argv[1],"rb"))==NULL)
    {
        printf("cannot open  file\n");
        exit(1);
    }

    printf("enter byte to seek to");
    scanf("%ld" , &loc);
    if(fseek(fp,loc,SEEK_SET))
    {
        printf("seek error\n");
        exit(1);
    }

    printf("value at loc %ld is %d" , loc , getc(fp));
    fclose(fp);

    return 0;
}
