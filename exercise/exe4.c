#include<stdio.h>
#include<stdlib.h>

int main(int argc , char *argv[])
{
    FILE *fp;
    unsigned count;

    if(argc!=2)
    {
        printf("file name missing\n");
        exit(1);
    }
    if((fp = fopen(argv[1],"rb"))==NULL)
    {
        printf("cannot open file\n");
        exit(1);
    }
    count =0;
    while(!feof(fp))
    {
        fgetc(fp);
        if(ferror(fp))
        {
            printf("file error\n");
            exit(1);
        }
        count++;
    }


    printf("file has %u bytes" , count-1);
    fclose(fp);
    return 0 ;
}
