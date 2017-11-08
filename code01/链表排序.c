#include <stdio.h>
#include <stdlib.h>
int len;
struct NUM
{
  int n;
  struct NUM *nextptr;
};
typedef struct NUM Num;
typedef Num* Numptr;
void insert(Numptr*,int);
void destory(Numptr);
void printlist(Numptr);
int main()
{
    Numptr A=NULL;
    int num;
    printf("Please input a list(end by -1):");
    scanf("%d",&num);
    for(;num!=-1;)
    {
       insert(&A,num);
       scanf("%d",&num);
    }
    printf("The new list is:");
    printlist(A);
    destory(A);
    system("pause");
    return 0;
}
void insert(Numptr* sptr,int value)
{
   Numptr pre=NULL,cur=*sptr,newptr;
   newptr=(Numptr)malloc(sizeof(Num));
   if(newptr)
   {
     newptr->n=value;
     newptr->nextptr=NULL;
     for(;cur&&value>cur->n;)
       {
        pre=cur;
        cur=cur->nextptr;
       }
     if(pre==NULL)
       {
        newptr->nextptr=cur;
        *sptr=newptr;
        }
     else
        {
        pre->nextptr=newptr;
        newptr->nextptr=cur;
        }
   }
}
void printlist(Numptr headptr)
{
    while(headptr)
    {
        if(headptr->nextptr==NULL)
           printf("%d",headptr->n);
        else
           printf("%d ",headptr->n);
        headptr=headptr->nextptr;
    }
    printf("\n");
}
void destory(Numptr headPtr)
{
    Numptr tempPtr;
    while(headPtr!=NULL){
        tempPtr=headPtr;
        headPtr=headPtr->nextptr;
        free(tempPtr);
    }
}
