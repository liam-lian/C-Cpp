#include <iostream>
#include <string.h>
using namespace std;
typedef struct node
{
    char data;
    struct node *lchild,*rchild;//�����
}node,*bitptr;
typedef struct qnode
{
     node data;
     struct qnode *next;
} qnode,*queptr;      //���н��
typedef  struct
{
  queptr front,rear;
} linkedqueue;       //����
//��ʼ������
void iniqueue(linkedqueue &Q)
{
    Q.front=new qnode;
    Q.rear=Q.front;
}
//��������Ԫ��
void Enqueue(linkedqueue &Q,node e)
{
    Q.rear->data=e;
    Q.rear->next=new qnode;
    Q.rear=Q.rear->next;
    return;
}
//�����п�
int Empty(linkedqueue &Q)
{
    if(Q.rear==Q.front) return 1;
    return 0;
}
//ȥ����ͷ������û�п��ǿն��У����������Ѿ��ų��յĿ��ܣ�
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
//����α���
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
