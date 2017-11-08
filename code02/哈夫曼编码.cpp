#include <iostream>
#include <fstream>
using namespace std;
int sum=0;//记录哈夫曼编码的编码总长度
typedef struct HuffNode
{
    char ID;
    int weight;
    struct HuffNode *left,*right,*next;
} HuffMan;
//依照权值由小到大的顺序建立链表
void insertqueue(HuffMan *H,HuffMan *node)
{
    HuffMan *h=H;
    for(;h->next;h=h->next)
      if(node->weight<=h->next->weight)
      {
         node->next=h->next;
         h->next=node;
         return;
      }
    h->next=node;
    node->next=NULL;
}
//判断队列是否空
bool Empty(HuffMan *H)
{
    if(H->next==NULL)
        return 1;
    return 0;
}
//删除权值最小元素
HuffMan* Dequeue(HuffMan *H)
{
    HuffMan* huf;
    huf=H->next;
    H->next=H->next->next;
    return huf;
}
void print(HuffMan* root,int n,bool *code)
{
    if(root)
    {
      if(!root->left&&!root->right)
      {
         cout<<root->ID<<" "<<root->weight<<" ";
         for(int i=0;i<=n-1;i++)
           cout<<code[i];
         cout<<" "<<n<<endl;
         sum+=root->weight*n;
      }
     code[n]=0;
     print(root->left,n+1,code);
     code[n]=1;
     print(root->right,n+1,code);
    }
}
HuffMan* creatTree(HuffMan *H)//建立哈夫曼树
{
    HuffMan *huf1,*huf2;
    HuffMan *root;
    while(!Empty(H))
    {
     huf1=Dequeue(H);
     huf2=Dequeue(H);
     root=new HuffMan;
     root->left=huf1;
     root->right=huf2;
     root->weight=huf1->weight+huf2->weight;
     if(!Empty(H))
        insertqueue(H,root);
    }
    return root;
}
int main()
{
    char ch;
    int ele[27]={0},length=0;//length记录文件的字符数量
    bool code[20]={0};
    HuffMan *H=new HuffMan;
    H->next=NULL;
    ifstream file("huffman.txt");
    while(!file.eof())
    {
        file>>ch;
        //要处理大写字母
        if(ch>='A'&&ch<='Z') ch+=32;
        if(ch=='#') ele[26]++;
        else ele[ch-'a']++;
    }
    file.close();
    for(int i=0;i<=26;i++)
    {
        HuffMan *temp=new HuffMan;
        temp->weight=ele[i];
        length+=ele[i];
        temp->ID='a'+i;
        if(i==26) temp->ID='#';
        temp->left=temp->right=NULL;
        insertqueue(H,temp);
    }
    HuffMan* root=creatTree(H);
    print(root,0,code);
    cout<<length*5<<endl;//等长编码
    cout<<sum<<endl;//哈夫曼编码
    return 0;
}



