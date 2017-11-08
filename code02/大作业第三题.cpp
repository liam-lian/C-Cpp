//�������ϻ���ҵ ��״
#include <iostream>
#include <string.h>
using namespace std;
int T=1;
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
//����������������ҵ�m��λ��
int select(char m,char*a,int q)
{
    for(int i=0;i<q;i++)
      if(a[i]==m)
        return i;
    return -1;
}
//������
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
//����������ݹ飩
void  Postorder(bitptr t)
{
  if(t)
  {
    Postorder (t->lchild);
    Postorder (t->rchild);
    cout<<t->data;
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
//�ҵ�·�������������ҵ��˳���
void search(char*a,char c,bitptr m,int n)
{

    if(c==m->data)
    {
       a[n]=c;
       cout<<"�Ӹ����ý���·��Ϊ��";
       for(int i=0;i<n;i++) cout<<a[i]<<"->";
       cout<<a[n]<<endl;
       T=0;//�ҵ��ı�־��
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
    cout<<"����ǰ��������� ";
    cin>>pre;
    cout<<"��������������� ";
    cin>>mid;
    createtree(m,pre,mid,strlen(pre));
    cout<<"�����������Ϊ: ";
    Postorder(m);
    cout<<endl<<"����α���������Ϊ��";
    levelordr(m);
    cout<<endl<<"����Ҫ���ҵĽ�㣺";
    cin>>c;
    search(a,c,m,0);
    if(T) cout<<"δ�ҵ��ý��";
    return 0;
}
