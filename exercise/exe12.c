#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc , char *argv[])
{
    FILE *fp;
    unsigned char ch , val;
    if(argc!=3)
    {
        printf("usage : find<filename> <value>\n");
        exit(1);
    }
    if((fp = fopen(argv[1],"rb"))==NULL)
    {
        printf("cannot open  file\n");
        exit(1);
    }

    val = atoi(argv[2]);

    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch==val)
        {
            printf("found value at %ld\n" , ftell(fp));
        }
    }

    fclose(fp);

    return 0;
}
