#ifndef AC_DFA_H_INCLUDED
#define AC_DFA_H_INCLUDED

#define ChildNum 16
#define BOOL int
#define TRUE 1
#define FALSE 0
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


#include "iostream"
#include "queue"
#include <string.h>
using namespace std;


int line=0;
//树节点，每个节点保存的是4bit数据
//使用unsigned char，确保为正，可直接作为child数组下标是索引
struct AC_Node{
    unsigned char value;
    struct AC_Node *child[ChildNum];
    struct AC_Node *parent;
    struct AC_Node *fail;
    BOOL isOutput;
};

struct AC_Node rootNode;

//初始化根节点

int init(){
    rootNode.isOutput=FALSE;
    rootNode.parent=NULL;
    rootNode.fail=NULL;
    for (int i = 0; i < ChildNum; i++)
      {
        rootNode.child[i]=NULL;
      }
}

//高四位
unsigned char gethigh4bit(unsigned char c){
   return (c & 240)>>4;
}
//低四位
unsigned char getlow4bit(unsigned char c){
  return (c & 15);
}
 
//逆序输出，先将两个节点拼接起来作为一个char，推入到stack中，最后反向读取栈
unsigned char*  ReverseOutput(struct AC_Node* node){
     if(node==NULL)
        return 0;
     setempty();
     while(node->parent!=NULL&&node->parent->parent!=NULL){

        unsigned char val=node->value+node->parent->value*16;
        push(val);
        node=node->parent->parent;
     }
    return toString();
}


 FILE* fpOut;

//仅仅作为测试，测试反向输出的结果是否正确
void write2File(int index,unsigned char * z){
     fprintf(fpOut,"%d----%s\n",index,z);
   // fclose(fpOut);
}



int createTree(unsigned char val[]){


//  printf("val=%s",val);

   if(val==NULL)
      return 0;

   int i,j;
   struct AC_Node *parent=&rootNode;


   for(i=0;!(val[i]=='\n'||val[i]=='\0');i++){

      unsigned char high4bit=gethigh4bit(val[i]);
      unsigned char low4bit=getlow4bit(val[i]);
      
      struct AC_Node* newNode_high;
      if(parent->child[high4bit]==NULL){
          newNode_high=(struct AC_Node*)malloc(sizeof(struct AC_Node));
          for (j=0; j < ChildNum; j++)
            newNode_high->child[j]=NULL;
            
          newNode_high->parent=parent;
          newNode_high->value=high4bit;
          newNode_high->fail=NULL;
          newNode_high->isOutput=FALSE;
          parent->child[high4bit]=newNode_high;
      }
      else{
          newNode_high=parent->child[high4bit];
      }
      
      struct AC_Node* newNode_low;
      if(newNode_high->child[low4bit]==NULL){
          newNode_low=(struct AC_Node*)malloc(sizeof(struct AC_Node));
          for (j=0; j < ChildNum; j++)
            newNode_low->child[j]=NULL;

          newNode_low->parent=newNode_high;
          newNode_low->value=low4bit;
          newNode_low->fail=NULL;  
          newNode_high->child[low4bit]=newNode_low;
          newNode_low->isOutput=FALSE;
      }
      else{
        newNode_low=newNode_high->child[low4bit];
      }
     
      
      // printf("%x\n",newNode_high);
      // printf("%x\n",newNode_low);

      if(val[i+1]=='\n'||val[i+1]=='\0'){
        newNode_low->isOutput=TRUE;
      }
     
      parent=newNode_low;
    }

//下面的两行作为测试，从每一个关键字的最后往前回溯，讲这个关键字输出到文件里面测试是否正确
   // unsigned char* zzzz=ReverseOutput(parent);
   // write2File(zzzz);
    
   return 1;
}


struct AC_Node* ishaswordchild(struct AC_Node* node,unsigned char high,unsigned char low){

     
     if(node==NULL){
        printf("ERROR\n");
        return NULL;
     }
    if(node->child[high]!=NULL && node->child[high]->child[low]!=NULL){
      return node->child[high]->child[low];
    }
    return NULL;
}


struct AC_Node* search_position=&rootNode;
int SearchIndexBase=0;


void  search(unsigned char *ch,int len){

    //printf("%d\n", len);
    struct AC_Node* lasthalfByteNode,*failNode;
    unsigned char* keyword;
    
    int index=0;

    while(index<len){  

        //struct AC_Node* temp=search_position;
    
        unsigned char high,low;

        high=gethigh4bit(ch[index]);
        low=getlow4bit(ch[index]);
    
        lasthalfByteNode=ishaswordchild(search_position,high,low);
        
        if(lasthalfByteNode!=NULL){
           if(lasthalfByteNode->isOutput){
                line++;
               keyword=ReverseOutput(lasthalfByteNode);
               write2File(SearchIndexBase+index-getSize(),keyword);
               
           }
           
           // modify on 10.17
           failNode=lasthalfByteNode->fail;
           while(failNode!=&rootNode){
               if(failNode->isOutput){
                 line++;
                 keyword=ReverseOutput(failNode);
                 write2File(SearchIndexBase+index-getSize(),keyword);
               }
               failNode=failNode->fail;
           }

           search_position=lasthalfByteNode;
           index++;
        }
        else{
           if(search_position==&rootNode)
                index++;
             else
                search_position=search_position->fail;
           //printf("%x\n", search_position);
        }
    }
    SearchIndexBase+=len;
}

struct AC_Node * words[16*16];
int wordsCount=0;

void calAllwords(struct AC_Node* node){

    int i,j;
    struct AC_Node* tmp;
    wordsCount=0;
    for(i=0;i<ChildNum;i++){
      if(node->child[i]!=NULL){
         tmp=node->child[i];
        for (j = 0; j <ChildNum; ++j)
        {
           if(tmp->child[j]!=NULL)
              words[wordsCount++]=tmp->child[j];
        }
      }
    }
}

struct AC_Node* getlastWord(struct AC_Node* node){
   return node->parent->parent;
}

void calfail(){
   
    queue<struct AC_Node*> q;
    queue<struct AC_Node*> qtmp;

    struct AC_Node* tmp,*parent;

    calAllwords(&rootNode);

    rootNode.fail=&rootNode;

   int wordsIndex=0;
   while(wordsIndex<wordsCount){
      qtmp.push(words[wordsIndex]);
      words[wordsIndex]->fail=&rootNode;

      //printf("%x==%x\n",words[wordsIndex],words[wordsIndex]->fail);

      wordsIndex++;
   }
   

   while(!qtmp.empty()){
      tmp=qtmp.front();
      qtmp.pop();
      calAllwords(tmp);
      for(wordsIndex=0;wordsIndex<wordsCount;wordsIndex++){
         q.push(words[wordsIndex]);
      } 
   }

   
   // here is with no content
   while(!q.empty()){
     
      tmp=q.front();
      q.pop();

     // printf("%x\n",tmp);

      parent=getlastWord(tmp);
      
      unsigned char high = tmp->parent->value;
      unsigned char low = tmp->value;
     
      //NULL
      struct AC_Node * zzz;
      while((zzz=ishaswordchild(parent->fail,high,low))==NULL){
          if(parent==&rootNode) break;
          parent=parent->fail;
      }

      //tmp->fail=parent->fail;
      if(zzz==NULL){
        tmp->fail=&rootNode;
      }
      else
        tmp->fail=zzz;
      
     // printf("%x====%x\n",tmp,tmp->fail );
      

      calAllwords(tmp);

      wordsIndex=0;
      while(wordsIndex<wordsCount){

        q.push(words[wordsIndex]);
        wordsIndex++;
     }
   }
}



#endif // AC_DFA_H_INCLUDED
