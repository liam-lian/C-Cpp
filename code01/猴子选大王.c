#include <stdio.h>
#include <stdlib.h>
struct King
{
    int num;
    struct King *nextptr;
};
int main()
{
   struct King *headptr,*current,*last;
   int i,n,k;
   scanf("%d%d",&n,&k);
   headptr=malloc(sizeof(struct King));
   headptr->num=1;
   last=headptr;
   for(i=2;i<=n;i++)
   {
      current=malloc(sizeof(struct King));
      current->num=i;
      last->nextptr=current;
      last=current;
   }
   last->nextptr=headptr;
   current=headptr;
   while(current->nextptr!=current)
   {

      for(i=1;i<k;i++)
        {
          last=current;
          current=current->nextptr;
        }
      printf("%d ",current->num);
      last->nextptr=current->nextptr;
      free(current);
      current=last->nextptr;
   }
    printf("\nThe King is:%d \n",current->num);
    free(current);
    system("pause");
    return 0;
}
