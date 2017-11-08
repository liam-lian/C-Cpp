#include <iostream>
#include <string.h>
using namespace std;
typedef struct node
{
    char data;
    struct node *lchild,*rchild;//数结点
}node,*bitptr;
typedef struct qnode
{
     node data;
     struct qnode *next;
} qnode,*queptr;      //队列结点
typedef  struct
{
  queptr front,rear;
} linkedqueue;       //队列
//初始化队列
void iniqueue(linkedqueue &Q)
{
    Q.front=new qnode;
    Q.rear=Q.front;
}
//向队列添加元素
void Enqueue(linkedqueue &Q,node e)
{
    Q.rear->data=e;
    Q.rear->next=new qnode;
    Q.rear=Q.rear->next;
    return;
}
//队列判空
int Empty(linkedqueue &Q)
{
    if(Q.rear==Q.front) return 1;
    return 0;
}
//去队列头（这里没有考虑空队列，主函数中已经排除空的可能）
node Dequeue(linkedqueue &Q)
{
    queptr m=Q.front;
    node c=m->data;
    Q.front=Q.front->next;
    delete m;
    return c;
}
int getpos(char*a,int n)
{
    int flag=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]=='(') flag++;
        if(a[i]==')') flag--;
        if(a[i]==','&&flag==1)
        return i;
    }
}
void createtree(bitptr &m,char *a,int n)
{
    if(a[0]=='#')
    {   m=NULL;
        return;
    }
    m=new node;
    m->data=a[0];
    if(a[1]=='(')
    {
        int pos=getpos(a,n);
        createtree(m->lchild,&a[2],pos-2);
        createtree(m->rchild,&a[pos+1],n-pos-1);
    }
    else
    {
        m->lchild=NULL;
        m->rchild=NULL;
        return;
    }
}
//按层次遍历
void levelordr(bitptr t)
{
    if(t)
    {
       linkedqueue q;
       iniqueue(q);
       Enqueue(q,*t);
       while(!Empty(q))
       {
           node temp=Dequeue(q);
           cout<<temp.data;
           if(temp.lchild) Enqueue(q,*(temp.lchild));
           if(temp.rchild) Enqueue(q,*(temp.rchild));
       }
    }
}
int main()
{
    bitptr m;
    char a[100];
    cin>>a;
    createtree(m,a,strlen(a));
    levelordr(m);
    return 0;
}
