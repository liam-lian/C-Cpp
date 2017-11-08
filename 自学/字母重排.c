#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Comstr(const void*_a,const void*_b)
  {
      char *a=(char*)_a,*b=(char*)_b;
      return strcmp(a,b);
  }
int Comchar(void*_a,void*_b)
  {
      char *a=(char*)_a,*b=(char*)_b;
      return *a-*b;
  }
int main()
{
    char word[100][10],sorted[100][10],newword[100][10];
    int j,i,n;
    for(i=0;;i++)
    {
        scanf("%s",word[i]);
        if(word[i][0]=='*')
          break;
    }
    n=i;
    qsort(word,n,sizeof(word[0]),Comstr);//对单词排序
    for(j=0;j<i;j++)
    {
        strcpy(sorted[j],word[j]);
        qsort(sorted[j],strlen(sorted[j]),sizeof(char),Comchar);//对每个单词排序
    }
    for(i=0;;i++)
    {
        scanf("%s",newword[i]);
        if(newword[i][0]=='#')
          break;
    }
    for(j=0;j<i;j++)
    {
        int p,found=0;
        qsort(newword[j],strlen(newword[j]),sizeof(char),Comchar);
        for(p=0;p<n;p++)
          if(strcmp(newword[j],sorted[p])==0){
            printf("%s ",word[p]);
            found=1;
            }
        if(!found) printf(":(");
        printf("\n");
    }
    return 0;
}
