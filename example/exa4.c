#include<stdio.h>
#include<stdlib.h>

int main (int argc , char *argv[])
{
    FILE *fp1 , *fp2;
    char ch1 , ch2, same;
    unsigned long l ;

    if (argc!=3)
    {
        printf("usage: compare <file 1> <file 2>\n");
        exit(1);
    }

    if((fp1 = fopen(argv[1],"rb"))==NULL)
    {
        printf("cannot open 1st file\n");
        exit(1);
    }
    if((fp2 = fopen(argv[2],"rb"))==NULL)
    {
        printf("cannot open 2nd file\n");
        exit(1);
    }

    l=0;
    same =1;

    while(!feof(fp1))
    {
        ch1 =fgetc(fp1);
        if(ferror(fp1))
        {
            printf("error reading 1st file\n");
            exit(1);
        }
        ch2 =fgetc(fp2);
        if(ferror(fp2))
        {
            printf("error reading 2nd file\n");
            exit(1);
        }
        if(ch1!=ch2)
        {
            printf("files differ at byte number %lu" , l);
            same = 0;
            break;
        }l++;
    }
    if(same)
    {
        printf("files are the same \n");
    }
    if(fclose(fp1)==EOF)
    {
        printf("error closing 1st file\n");
        exit(1);
    }
        if(fclose(fp2)==EOF)
    {
        printf("error closing 2nd file\n");
        exit(1);
    }
    return 0;

}
