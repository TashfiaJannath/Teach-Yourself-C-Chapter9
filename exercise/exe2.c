#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int count [26];

int main(int argc , char *argv[])
{
    FILE *fp;
    char ch;
    int i;
    if(argc!=2)
    {
        printf(" file name missing\n");
        exit(1);
    }
    if((fp = fopen(argv[1],"r"))==NULL)
    {
        printf("cannot open  file\n");
        exit(1);
    }
    while((ch=fgetc(fp))!= EOF)
       {
        ch=toupper(ch);
        if(ch>='A' && ch<='Z')
        {
            count[ch-'A']++;
        }
       }
       for(i=0;i<26;i++)
       {
           printf("%c occurred %d times\n" , i+'A' , count[i]);
       }
       fclose(fp);
       }
