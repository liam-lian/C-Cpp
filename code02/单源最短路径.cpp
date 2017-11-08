#include <iostream>
#include <fstream>
#define Maxsize 50
#define Maxint 10000
using namespace std;
void Dijkstra(double **adj,double *dist,int *pre,int v,int n)
{
    bool isdone[Maxsize];
    for(int i=1;i<=n;i++)
    {
        dist[i]=adj[v][i];
        isdone[i]=0;
        if(dist[i]==-1) pre[i]=0;
        else pre[i]=v;
    }
    dist[v]=0;
    isdone[v]=1;
    for(int i=1;i<n;i++)
    {

        int temp=Maxint,u=v;
        for(int j=1;j<=n;j++)
            if((!isdone[j])&&dist[j]!=-1&&dist[j]<temp)
            {
                u=j;
                temp=dist[j];
            }
        isdone[u]=1;
        for(int j=1;j<=n;j++)
          if((!isdone[j])&&adj[u][j]!=-1)
              if(dist[u]+adj[u][j]<dist[j]||dist[j]==-1)
              {
                 dist[j]=dist[u]+adj[u][j];
                 pre[j]=u;
              }
    }
}
void findroute(int *pre,int *name,int n,ofstream &file)
{
    if(n==0) return;
    findroute(pre,name,pre[n],file);
    file<<name[n]<<"["<<n<<"]"<<" ";
}
void Shortestpath(int source,int n,fstream &file,ofstream &outfile)
{
    int name[Maxsize],pre[Maxsize];
    double **adj=new double*[Maxsize],dist[Maxsize];
    for(int i=0;i<Maxsize;i++) adj[i]=new double[Maxsize];
    for(int i=1;i<=n;i++) file>>name[i];
    for(int i=1;i<=n;i++)
       for(int j=0;j<=n;j++)
          file>>adj[i][j];
   Dijkstra(adj,dist,pre,source,n);
   for(int i=1;i<=n;i++)
    if(i!=source)
      {
      outfile<<name[source]<<"��"<<name[i]<<"���·��:";
      findroute(pre,name,i,outfile);
      outfile<<endl;
      }
   cout<<dist[n]<<endl;
}
int main()
{
   fstream file1("����1-1.ͼ���ڽӾ���1.txt"),
           file2("����1-1.ͼ���ڽӾ���2.txt");
   ofstream outfile("output.txt",ios::ate);
   outfile<<"��һ��42���ڵ�:"<<endl;
   Shortestpath(1,42,file1,outfile);
   outfile<<"�ڶ���22���ڵ�:"<<endl;
   Shortestpath(1,22,file2,outfile);
   return 0;
}
