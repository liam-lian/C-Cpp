//第三次上机作业 连状
#include <iostream>
#include <string.h>
using namespace std;
int T=1;
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
//在中序遍历序列中找到m的位置
int select(char m,char*a,int q)
{
    for(int i=0;i<q;i++)
      if(a[i]==m)
        return i;
    return -1;
}
//建立树
void createtree(bitptr &m,char *pre,char *mid,int n)
{
    m=new node;
    m->data=pre[0];
    int p=select(pre[0],mid,n);
    if(p>=1)  createtree(m->lchild,&pre[1],mid,p);
    else      m->lchild=NULL;
    if(p+1<n) createtree(m->rchild,&pre[p+1],&mid[p+1],n-1-p);
    else      m->rchild=NULL;
}
//后序遍历（递归）
void  Postorder(bitptr t)
{
  if(t)
  {
    Postorder (t->lchild);
    Postorder (t->rchild);
    cout<<t->data;
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
//找到路径（暴力搜索找到退出）
void search(char*a,char c,bitptr m,int n)
{

    if(c==m->data)
    {
       a[n]=c;
       cout<<"从根到该结点的路径为：";
       for(int i=0;i<n;i++) cout<<a[i]<<"->";
       cout<<a[n]<<endl;
       T=0;//找到的标志量
       return ;
    }
    a[n++]=m->data;
    if(m->lchild) search(a,c,m->lchild,n);
    if(m->rchild) search(a,c,m->rchild,n);
}
int main()
{
    bitptr m;
    char c,pre[100],mid[100],a[100];
    cout<<"输入前序遍历序列 ";
    cin>>pre;
    cout<<"输入中序遍历序列 ";
    cin>>mid;
    createtree(m,pre,mid,strlen(pre));
    cout<<"后序遍历序列为: ";
    Postorder(m);
    cout<<endl<<"按层次遍历的序列为：";
    levelordr(m);
    cout<<endl<<"输入要查找的结点：";
    cin>>c;
    search(a,c,m,0);
    if(T) cout<<"未找到该结点";
    return 0;
}
