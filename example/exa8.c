#include<stdio.h>
#include<stdlib.h>

double d[10]=
{
    10.23 ,19.87, 1002.23 , 12.9 , 0.897,
    11.45 , 75.34 , 0.0 , 1.01, 875.875
};
int main (void)
{
    int i ;
    FILE *fp;
    if((fp = fopen("myfile1","wb"))==NULL)
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

    for(i=0;i<10;i++)
    {
        d[i]= -1.0;
    }

    if(fread(d, sizeof d,1,fp)!=1)
        {
            printf("read error\n");
            exit(1);
        }
        fclose(fp);

    for(i=0;i<10;i++)
    {
        printf("%f " , d[i]);n
    }
    return 0 ;



}
