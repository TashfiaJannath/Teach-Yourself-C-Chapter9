#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(int argc , char *argv[])
{
    FILE *fp;
    char str[80] , ch;
    int count;
    if(argc!=2)
    {
        printf("usage : display<file>\n");
        exit(1);
    }
    if((fp = fopen(argv[1],"r"))==NULL)
    {
        printf("cannot open  file\n");
        exit(1);
    }

    count =0;
    while(!feof(fp))
    {
        fgets(str , 79 , fp);
        printf("%s" , str);
        count++;

        if(count==23)
        {
            printf("more? (y/n)");
            gets(str);
            if(toupper(*str)=='N')
            {
                break;
            }
            count=0;
        }
    }
    fclose(fp);
    return 0 ;
}
