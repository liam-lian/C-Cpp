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
    struct wujin a={0,"",0,0.0};
    FILE* fptr;
    int i;
    if((fptr=fopen("hard.dat","w"))==NULL)
       printf("file could not be opened\n");
    else
     {
        for(i=1;i<=100;i++)
          fwrite(&a,sizeof(struct wujin),1,fptr);
        scanf("%d",&a.n);
        while(a.n)
          {
              scanf("%s%d%f",a.a,&a.num,&a.count);
              fseek(fptr,(a.n-1)*sizeof(struct wujin),SEEK_SET);
              fwrite(&a,sizeof(struct wujin),1,fptr);
              scanf("%d",&a.n);
          }
                  fclose(fptr);

     }
     if((fptr=fopen("hard.dat","rb+"))==NULL)
       printf("file could not be opened\n");
     else
       while(!feof(fptr))
        {
          fread(&a,sizeof(struct wujin),1,fptr);
          if(a.n)
            printf("%d %s %d %.2f\n",a.n,a.a,a.num,a.count);
       }
    fclose(fptr);
    system("pause");
    return 0;
}
