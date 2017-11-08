  #include <stdio.h>
#include <stdlib.h>
#define INF 1000000000
struct num
{
    int data;
    struct num* nextptr;
};
typedef struct num NUM;
typedef NUM* NUMPTR;
NUMPTR startlist();
int main()
{

    NUMPTR headptr=NULL,tempptr=NULL;
    int max=0,min=INF,sum=0;
    printf("Please input a series of integers:");
    headptr=startlist();
    for(;headptr!=NULL;)
    {
        max=headptr->data>max?headptr->data:max;
        min=headptr->data<min?headptr->data:min;
        sum+=headptr->data;
        headptr=headptr->nextptr;
    }
    printf("The maximum,minmum and the total are:%d %d %d\n",max,min,sum);
    for(;headptr!=NULL;)
    {
        tempptr=headptr;
        free(headptr); 
        headptr=tempptr->nextptr;

    }
    system("pause");
    return 0;
}
NUMPTR startlist()
{
    int num;
    NUMPTR headptr=NULL,currentptr=NULL,lastptr=NULL;
    scanf("%d",&num);
    for(;num!=-1;)
    {
        currentptr=(NUMPTR)malloc(sizeof(NUM));
        if(currentptr!=NULL)
        {
            currentptr->data=num;
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
    lastptr->nextptr=NULL;
    return headptr;
} 
