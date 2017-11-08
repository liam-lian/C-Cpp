#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int solve=0;
void bag(int n,float T,float *w,int* ans,int cur);
int main()
{
    float T,w[100];
    int n,ans[100]={0};
    cin>>T>>n;
    for(int i=0;i<n;i++)
        cin>>w[i];
    bag(n,T,w,ans,0);
    if(!solve) cout<<"NO ANSWER"<<endl;
    return 0;
}
void bag(int n,float T,float *w,int* ans,int cur)
{
    float tot=0;
    for(int i=0;i<n;i++)
      if(ans[i])
       tot+=w[i];
   if(fabs(tot-T)<=1e-6){
      for(int i=0;i<n;i++)
         if(ans[i])
            cout<<"w"<<i+1<<" ";
      cout<<endl;
      solve=1;
      return ;
   }
   //if(fabs(tot-T)>1e-5) return;对于质量和已经超过T的直接return（疑问）
    else if(cur>=n) return;//已经选完,return
      else
      {
         ans[cur]=0;//不选第cur个
         bag(n,T,w,ans,cur+1);
         ans[cur]=1;//选第cur个
         bag(n,T,w,ans,cur+1);
      }
}
