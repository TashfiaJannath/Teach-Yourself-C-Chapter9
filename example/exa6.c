#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc , char *argv[])
{
    FILE *fp;
    double ld;
    int d;
    char str[80];
    if(argc!=2)
    {
        printf("specify file name\n");
        exit(1);
    }

    fprintf(fp , "%f %d %s" , 12345.342, 1908 , "hello");
    fclose(fp);

if((fp = fopen(argv[1],"w"))==NULL)
    {
        printf("cannot open  file\n");
        exit(1);
    }
    if((fp = fopen(argv[1],"r"))==NULL)
    {
        printf("cannot open  file\n");
        exit(1);
    }
    fscanf(fp, "%lf%d%s", &ld , &d , str);
    printf("%f %d %s" , ld , d , str);
    fclose(fp);

    return 0;
}
