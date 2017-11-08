#include <iostream>

using namespace std;

struct node{
    int coef;
    int exp;
    struct node* next;
};
typedef node Node;
void add(Node *link1,Node *link2);
int main()
{
    int x,y,z;
    Node *link1=new Node;
    link1->next=NULL;
    Node *link2=new Node;
    link2->next=NULL;
    Node *temp=link1;
    bool x2=false;
    while(cin>>x&&!x2){
       if(x=='s')
       {
          temp=link2;
          cin>>x;
       }
       if(x=='z')
        break;
       cin>>y;
       temp->next=new Node;
       temp=temp->next;
       temp->coef=x;
       temp->exp=y;
       temp->next=NULL;
    }


    while(link2->next){
        cout<<link2->next->coef<<" "<<link2->next->exp<<endl;
        link2=link2->next;
    }

    add(link1,link2);
    while(link1->next)
    {
        cout<<link1->next->coef<<" "<<link1->next->exp<<endl;
        link1=link1->next;
    }
    cout<<"x"<<z;
    return 0;
}

void mul(Node* link,Node * node)
{
    Node *thelink=link->next;
    while(thelink){
        thelink->coef=thelink->coef*node->coef;
        thelink->exp=thelink->exp+node->exp;
        thelink=thelink->next;
    }
}

void add(Node *link1,Node *link2){
    Node *tempnode=link1;
    Node *tempnode2=link2->next;
    while(tempnode->next&&tempnode2)
    {
        if(tempnode2->exp==tempnode->next->exp)
        {
            tempnode->next->coef+=tempnode2->coef;
            tempnode2=tempnode2->next;
        }
        if(tempnode2->exp>tempnode->next->exp)
        {
            tempnode2->next=tempnode->next;
            tempnode->next=tempnode2;
            tempnode2=tempnode2->next;
        }
        tempnode=tempnode->next;
    }
    if(tempnode2){
       tempnode->next=tempnode2;
    }
}
