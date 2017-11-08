#include <iostream>
#include <cstdio>
#include <malloc.h>
#define INISIZE 100
#define ADDSIZE 10
using namespace std;
typedef struct
{
    char* top;
    char* bottom;
    int stacksize;
} mstack;
void initial(mstack &S)
{
    S.bottom=(char *)malloc(INISIZE*sizeof(char));
    S.top=S.bottom;
    S.stacksize=INISIZE;
}
void push(mstack &S,char e)
{
    if(S.top-S.bottom>=S.stacksize)
    {
        S.bottom=(char *)realloc(S.bottom,(INISIZE+ADDSIZE)*sizeof(char));
        S.top=S.bottom+S.stacksize;
        S.stacksize=INISIZE+ADDSIZE;
    }
    *S.top++=e;
}
char gettop(mstack &S)
{
    if(S.bottom==S.top) return 0;
    return *--S.top;
}
int isempty(mstack S)
{
    if(S.bottom==S.top) return 1;
    return 0;
}
int main()
{
    mstack S;
    initial(S);
    bool ok=1;
    char e;
    while((e=getchar())!='\n')
    {
        if(e=='('||e=='['||e=='{')
            push(S,e);
        if(e==')')
        {
            if(gettop(S)=='(') ;
            else
            {
              //cout<<"ERROR"<<endl;
              ok=0;
              break;
            }
        }
         if(e==']')
        {
            if(gettop(S)=='[') ;
            else
            {
              //cout<<"ERROR"<<endl;
              ok=0;
              break;
            }
        }
         if(e=='}')
        {
            if(gettop(S)=='{') ;
            else
            {
              //cout<<"ERROR"<<endl;
              ok=0;
              break;
            }
        }
    }
    if(!ok||!isempty(S)) cout<<"ERROR"<<endl;
    else if(ok) cout<<"RIGHT"<<endl;
    free(S.bottom);
    return 0;
}
