 #include <stdio.h>
#include <stdlib.h>
struct NUM
{
  int n;
  struct NUM *nextptr;
};
typedef struct NUM Num;
typedef Num* Numptr;
Numptr start(void);//创建链表
void printList(Numptr,int);//打印链表
void add(Numptr*,int);//在练表后添加元素
void destroyList(Numptr);//释放链表
int main(int argc, char *argv[])
{
  Numptr A=NULL,B=NULL,C1=NULL,C2=NULL,currentptra=NULL,currentptrb=NULL;
  int a,b;
  printf("Please input the elements of list A:");
  A=start();
  printf("Please input the elements of list B:");
  B=start();
  currentptra=A;
  while(currentptra)   //嵌套循环遍历两个链表中的所有元素
  {
    a=currentptra->n;
    currentptra=currentptra->nextptr;
    currentptrb=B;   //每次循环初始化
    int ok=1,ok1=0;
    while(currentptrb)
       {
       b=currentptrb->n;  
        if(a==b)
        {
         ok=0;
         ok1=1;
        }
       currentptrb=currentptrb->nextptr;
      }
    if(ok==1)
      add(&C1,a);
    if(ok1==1)
      add(&C2,a);
 }
  printList(C1,1);
  printList(C2,2);
  destroyList(A);
  destroyList(B);
  destroyList(C1);
  destroyList(C2);
  system("pause");
  return 0;
}
Numptr start(void)
{
   Numptr lastptr=NULL,currentptr=NULL,headptr=NULL;
   int num;
   scanf("%d",&num);
   while(num!=-1)
   {
       currentptr=malloc(sizeof(Num));
       if(currentptr)
       {
            currentptr->n=num;
            if(headptr==NULL)
            {
             headptr=currentptr;
             lastptr=currentptr;
            }
            else
            {
             lastptr->nextptr=currentptr;
             lastptr=currentptr;
            }
      }
     scanf("%d",&num);
  }
    if(headptr!=NULL)//解决了链表为空时存在的问题
      lastptr->nextptr=NULL;
    return headptr;
}
void add(Numptr *sptr,int value)
{
    Numptr newptr,cu=*sptr;
    newptr=(Numptr)malloc(sizeof(Num));
    if(newptr)
    {
        newptr->n=value;
        newptr->nextptr=NULL;
        if(cu==NULL)
          *sptr=newptr;//疑问？？？？？
        else
        {
        while(cu->nextptr)
          cu=cu->nextptr;
        cu->nextptr=newptr;
        }
    }
}
void destroyList(Numptr headPtr)
{
    Numptr tempPtr;
    while(headPtr!=NULL){
        tempPtr=headPtr;
        headPtr=headPtr->nextptr;
        free(tempPtr);
    }
}
void printList(Numptr currentPtr,int p)
{
    if(currentPtr==NULL)
      printf("There is no item in C%d list.\n",p);
    else
      {
        printf("The list C%d:",p);
        while(currentPtr!=NULL)
        {
            printf("%d ",currentPtr->n);
            currentPtr=currentPtr->nextptr;
        }
        printf("\n");
      }
}



