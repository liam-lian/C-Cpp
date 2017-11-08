//结构数组排序（成绩优先，相同时以名字顺序输出） 
#include <stdio.h>
#include <stdlib.h>
struct grade
{
  char a[20];
  int n;
};
  typedef struct grade G;
void temp(G *a,G *b);
int main(int argc, char *argv[])
{
    G q[100];
    int n,i,j=0,p,isok=1;;
    char w;
    printf("Please input the number of the students:");
    scanf("%d",&n);
    getchar();
    printf("The name and the total score are:\n");
    for(i=0;i<=n-1;i++)
      {  
         q[i].n=0;                                        
        while((w=getchar())!='\n')
           {
              if(w>='0'&&w<='9')
                   q[i].n=q[i].n*10+(w-'0');
               else
                  { 
                   q[i].a[j]=w;
                   j++;
                   }            
            }
         q[i].a[j]='\0';    
         j=0;     
       }   
   printf("The students's information:\n");          
   for (i=0;i<n-1;i++)
		for (j=0;j<n-i-1;j++)
          {
           if(q[j].n<q[j+1].n)
              temp(&q[j],&q[j+1]);
           if(q[j].n==q[j+1].n)
              for(p=0;isok==1;p++)
                 {
                  if(q[j].a[p]!=q[j+1].a[p])
                       isok=0;
                  if(q[j].a[p]>q[j+1].a[p])
                       temp(&q[j],&q[j+1]);
                  }  
              isok=1;       
           }    
          
     for(i=0;i<=n-1;i++)
       {
           printf("Name:");             
           puts(q[i].a);                
           printf("total:%d\n\n",q[i].n);
        }                                                                              
  system("PAUSE");	
  return 0;
}
void temp(G *a,G *b)
{
  G c;   
  c=*a;
  *a=*b;
  *b=c;
}  
