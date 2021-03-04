#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc , char *argv[])
{
    FILE *fp;
    char str[80];
    if(argc!=2)
    {
        printf("specify file name\n");
        exit(1);
    }
    if((fp = fopen(argv[1],"w"))==NULL)
    {
        printf("cannot open  file\n");
        exit(1);
    }
    printf("enter a blank line to stop\n");

    do{
        printf(": ");
        gets(str);
        strcat(str , "\n");
        if(*str != '\n')
            fputs(str , fp);
    }while(*str!='\n');
    fclose(fp);

    if((fp = fopen(argv[1],"r"))==NULL)
    {
        printf("cannot open file\n");
        exit(1);
    }

    do{
        fgets(str , 79 ,fp);
        if(!feof(fp))
            printf(str);
    }while(!feof(fp));
    fclose(fp);

    return 0;

}
