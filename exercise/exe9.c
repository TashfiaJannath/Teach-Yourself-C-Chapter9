#include<stdio.h>
#include<stdlib.h>

int main ()
{
    FILE *fp1,*fp2;
    double d;
    int i;
    if((fp1 = fopen("values","wb"))==NULL)
    {
        printf("cannot open  file\n");
        exit(1);
    }
    if((fp2 = fopen("count","wb"))==NULL)
    {
        printf("cannot open  file\n");
        exit(1);
    }
    d=1.0;
    for(i=0;d!=0.0 && i<32766;i++)
    {
        printf("enter a number (0 to quit)");
        scanf("%lf " , &d);
        fwrite(&d , sizeof d , 1 ,fp1 );
    }
     fwrite(&i , sizeof i , 1 ,fp2 );

     fclose(fp1);
     fclose(fp2);
     return 0;
}
