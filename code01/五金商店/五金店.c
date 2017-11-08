#include <stdio.h>
#include <stdlib.h>
struct wujin
{
    int n;
    char a[100];
    int num;
    float count;
};
main()
{
    struct wujin a,m={0,"",0,0.0};
    FILE* fptr;
    int i=1,p;
    printf("1-input the data.\n2-print the list.\n3-delete the data.\n4-update the data.\n5-the end of the system\n");//提示信息 
    scanf("%d",&p);
    if((fptr=fopen("hard.dat","w"))==NULL)
          printf("file could not be opened\n");
     else
         for(i=1;i<=100;i++)//初始化 
         {
            fwrite(&m,sizeof(struct wujin),1,fptr);
            fseek(fptr,i*sizeof(struct wujin),SEEK_SET);
         }
     fclose(fptr);
    while(p!=5)//p=5时结束 
    {
       if(p==1||p==4)//写入数据 
       {

         if((fptr=fopen("hard.dat","r+b"))==NULL)
            printf("file could not be opened\n");
         else
         {
          printf("please input the  data you want to update or input ,press 0 to end:\n");
          scanf("%d",&a.n);
          while(a.n)
           {
               scanf("%s%d%f",a.a,&a.num,&a.count);
               fseek(fptr,(a.n)*sizeof(struct wujin),SEEK_SET);
               fwrite(&a,sizeof(struct wujin),1,fptr);
               scanf("%d",&a.n);
           }
         fclose(fptr);
         }
       }
      if(p==2)
      {
        i=1;
        if((fptr=fopen("hard.dat","r+b"))==NULL)
           printf("file could not be opened\n");
        else
        {
        fseek(fptr,i*sizeof(struct wujin),SEEK_SET);
        fread(&a,sizeof(struct wujin),1,fptr);
        while(!feof(fptr))//输出非零数据 
         {

            if(a.n)
              printf("%d %s %d %.2f\n",a.n,a.a,a.num,a.count);
            i++;
            fseek(fptr,i*sizeof(struct wujin),SEEK_SET);
            fread(&a,sizeof(struct wujin),1,fptr);
         }
         fclose(fptr);
        }

      }
      if(p==3)
      {
          if((fptr=fopen("hard.dat","rb+"))==NULL)
           printf("file could not be opened\n");
        else
        {
        printf("please input the line of the data you want to delete:\n");//删除 
            scanf("%d",&i);
            fseek(fptr,i*sizeof(struct wujin),SEEK_SET);
            fwrite(&m,sizeof(struct wujin),1,fptr);
            fclose(fptr);
        }
      }
      printf("\n1-input the data.\n2-print the list.\n3-delete the data.\n4-update the data.\n5-the end of the system\n");
      scanf("%d",&p);
    }
    system("pause");
    return 0;
}
