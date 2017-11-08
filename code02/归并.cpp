#include <iostream>
#include <fstream>
#define Maxsize 1033
using namespace std;
//定义基站数类型
typedef struct
{
    int ENODEBID;
    float LONGITUDE,LATITUDE,K_DIST;
} station;
void Merge(station *s,station *t,int f,int r1,int r2)
{
    int sf=f,tf=r1+1,i=f;
    while(sf<=r1&&tf<=r2)
    {
         if(s[sf].K_DIST<=s[tf].K_DIST) t[i++]=s[sf++];
         else t[i++]=s[tf++];
    }
    while(sf<=r1) t[i++]=s[sf++];
    while(tf<=r2) t[i++]=s[tf++];
}
void Mergesort(station *T,int f,int r)
{
   station s[Maxsize-1];
   if(f<r){
    int m=(f+r)/2;
    Mergesort(T,f,m);
    Mergesort(T,m+1,r);
    Merge(T,s,f,m,r);
    for(int i=f;i<=r;i++)
       T[i]=s[i];
   }
}
int main()
{
    ifstream filedata("C:\\Users\\lianzhuang\\Desktop\\aaa\\basedata.txt");//打开源数据文件
    ofstream outfile("mergesort.txt");
    station data[Maxsize];
    for(int i=0;i<Maxsize;i++)
        filedata>>data[i].ENODEBID>>data[i].LONGITUDE>>data[i].LATITUDE>>data[i].K_DIST;
    Mergesort(data,0,Maxsize-1);
    for(int i=0;i<Maxsize;i++)
       outfile<<i<<" "<<data[i].ENODEBID<<" "<<data[i].LONGITUDE<<" "<<data[i].LATITUDE<<" "<<data[i].K_DIST<<endl;
    return 0;
}
