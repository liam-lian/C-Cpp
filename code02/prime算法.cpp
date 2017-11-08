#include <iostream>
#include <fstream>
#define Maxsize 50
#define INFINITE 10000
using namespace std;
int Prime(int n, double** adj,ofstream &outfile)
{
    double lowcost[Maxsize];
    int    closet[Maxsize];
    bool   ischoose[Maxsize];
    ischoose[1]=1;
    for(int i=2;i<=n;i++)
    {
       lowcost[i]=adj[1][i];
       closet[i]=1;
       ischoose[i]=0;
    }
    for(int i=1;i<n;i++)
    {
        double Min=INFINITE;
        int j=1;
        for(int k=2;k<=n;k++)
            if((!ischoose[k])&&lowcost[k]<Min)
        {
            Min=lowcost[k];
            j=k;
        }
        outfile<<j<<"-"<<closet[j]<<endl;
        ischoose[j]=1;
        for(int k=2;k<=n;k++)
            if((!ischoose[k])&&adj[j][k]<lowcost[k])
        {
            lowcost[k]=adj[j][k];
            closet[k]=j;
        }
    }
}
void MST(int n,fstream &file,ofstream &MSToutfile)
{
    int name[Maxsize];
    double **adj=new double*[Maxsize],dist[Maxsize],m;
    for(int i=0;i<Maxsize;i++) adj[i]=new double[Maxsize];
    for(int i=1;i<=n;i++) file>>name[i];
    for(int i=1;i<=n;i++)
       for(int j=0;j<=n;j++)
         {
            file>>m;
            if(m==-1) m=INFINITE;
            adj[i][j]=m;
         }
   Prime(n,adj,MSToutfile);
}
int main()
{
   fstream file1("附件1-1.图的邻接矩阵2.txt"),
           file2("附件1-1.图的邻接矩阵1.txt");
   ofstream outfile("MSToutput.txt",ios::ate);
   outfile<<"第一组22个节点:"<<endl;
   MST(22,file1,outfile);
   outfile<<"第二组42个节点:"<<endl;
   MST(42,file2,outfile);
}
