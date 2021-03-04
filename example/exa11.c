#include<stdio.h>
#include<stdlib.h>

double d[10]=
{
    10.23 ,19.87, 1002.23 , 12.9 , 0.897,
    11.45 , 75.34 , 0.0 , 1.01, 875.875
};
int main (void)
{
    long loc;
    double value;
    FILE *fp;
    if((fp = fopen("myfile","wb"))==NULL)
    {
        printf("cannot open  file\n");
        exit(1);
    }

        if(fwrite(d, sizeof d,1,fp)!=1)
        {
            printf("write error\n");
            exit(1);
        }
        fclose(fp);
    if((fp = fopen("myfile1","rb"))==NULL)
    {
        printf("cannot open  file\n");
        exit(1);
    }
    printf("which element?");
    scanf("%ld" , &loc);
    if(fseek(fp , loc*sizeof(double), SEEK_SET))
    {
        printf("seek error\n");
        exit(1);
    }

    fread(&value , sizeof(double), 1, fp);
    printf("element %ld is %f" , loc , value);

    fclose(fp);

    return 0 ;

    }
