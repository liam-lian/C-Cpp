#include <stdio.h>
#include <stdlib.h>
struct  student{   /*学生特殊信息结构类型*/
       char  no[7];         /*学号*/
       char  class[5];        /*班级*/
} ; 

struct  teacher{   /*教师特殊信息结构类型*/
       char  no[4];         /*工号*/
       char  class[5];        /*职称*/
       int startYear; /*开始工作年*/
} ; 
union A
{
      struct  student B;
      struct  teacher C;
};
struct R
{  
    char b[100];
    int a;
    int c;
    int e;
    union A A;   
};  
typedef struct R  b;            
int main()
{
    b p[100];    
    int n,i,z;
    scanf("%d",&n);
    scanf("%d",&z);
    for(i=1;i<=n;i++)
    {
       scanf("%s",p[i].b);
       scanf("%d",&p[i].a);
       scanf("%d",&p[i].c);
       scanf("%d",&p[i].e);
      if(z==0)
         {
          scanf("%s",p[i].A.B.no);
          scanf("%s",p[i].A.B.class);
         }
      else
         {
            scanf("%s",p[i].A.C.no);
            scanf("%s",p[i].A.C.class);
            scanf("%d",&p[i].A.C.startYear);
         }         
      }        
    for(i=1;i<=n;i++)
    {
      puts(p[i].b);
      printf("%d-%d-%d\n",p[i].a,p[i].c,p[i].e);
      if(z==0)
         {
          puts(p[i].A.B.no);
          puts(p[i].A.B.class);
         }
      else
         {
            puts(p[i].A.C.no);
            puts(p[i].A.C.class);
            printf("%d",p[i].A.C.startYear);
         }
}  
   system("PAUSE");
    return 0;
}
