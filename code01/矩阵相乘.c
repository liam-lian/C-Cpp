//�������
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    float a[100][100],b[100][100],c[100][100];
    int x,y,z,i,j,m;
    printf("����A���к���");
    scanf("%d %d",&x,&y);
    printf("����B����");
    scanf("%d",&z);
    printf("�������A\n");
   for(i=0;i<=x-1;i++)
      for(j=0;j<=y-1;j++)
         scanf("%f",&a[i][j]);
   printf("�������B\n");
   for(i=0;i<=y-1;i++)
       for(j=0;j<=z-1;j++)
          scanf("%f",&b[i][j]);
   for(i=0;i<=x;i++)
      for(j=0;j<=z;j++)
         for(m=0;m<=y;m++)
              c[i][j]+=a[i][m]*b[m][j];
   printf("A*B=\n");
   for(i=0;i<=x-1;i++)
      {
        for(j=0;j<=z-1;j++)
            printf("%-6f   ",c[i][j]);
       printf("\n");
       }
  system("PAUSE");
  return 0;
}
