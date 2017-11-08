#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#define Maxsize 30
#define INFINITE 100000
const double EARTH_RADIUS = 6378137;//赤道半径m
//定义基站数类型
typedef struct
{
    int ENODEBID;
    double LONGITUDE,LATITUDE;
} station;
double rad(double LatOrLon)
{
   return (LatOrLon*acos(-1))/180.0;
}
double GetDistance(station A,station B)
{

    double radLat1 = rad(A.LATITUDE);
    double radLat2 = rad(B.LATITUDE);
    double radlng1 = rad(A.LONGITUDE);
    double radlng2 = rad(B.LONGITUDE);
    //利用正弦余弦公式求距离
    double  s=acos(cos(radLat1)*cos(radLat2)*cos(radlng1-radlng2)+sin(radLat1)*sin(radLat2));
    s*=EARTH_RADIUS;
    return s;
}
typedef struct edge
{
    int start;
    int end;
    bool enable;//该边是否已经被选中了
    double dist;
}Edge;
int miniedge(Edge* v,int n)
{
    double min=INFINITE;
    int ans;
    for(int i=0;i<=n-1;i++)
        if(v[i].enable&&v[i].dist<min)
        {
            ans=i;
            min=v[i].dist;
        }
    return ans;
}
int findpre(Edge *v,int de,int n)
{
    for(int i=(de-1+n)%n;;i=(i-1+n)%n)
        if(v[i].enable==1) return i;
    return -1;
}
int findnext(Edge *v,int de,int n)
{
    for(int i=(de+1+n)%n;;i=(i+1+n)%n)
        if(v[i].enable==1) return i;
    return -1;
}
void Minweight(int n,station *data)
{
    Edge v[Maxsize],ans[Maxsize];
    int cou=1;
    double Length_Chord=0;//记录选中的弦长之和
    for(int i=0;i<=n-1;i++)
    {
        v[i].start=i;
        v[i].end=(i+2)%n;
        v[i].enable=1;
        v[i].dist=GetDistance(data[i],data[v[i].end]);
    }
    for(int i=1;i<=n-3;i++)
    {
        int dele=miniedge(v,n);
        Length_Chord+=v[dele].dist;
        v[findnext(v,dele,n)].enable=0;
        ans[cou++]=v[dele];
        int z=findpre(v,dele,n);
        v[z].end=findnext(v,v[z].end,n);
        v[z].dist=GetDistance(data[z],data[v[z].end]);
        v[dele].end=findnext(v,v[dele].end,n);
        v[dele].dist=GetDistance(data[dele],data[v[dele].end]);
    }
    //弦长加上n条边的长度
    Length_Chord*=2;
    for(int i=0;i<=n-2;i++) Length_Chord+=GetDistance(data[i],data[i+1]);
    Length_Chord+=GetDistance(data[n-1],data[0]);
    cout<<Length_Chord<<endl;
    for(int i=1;i<=n-3;i++)
      cout<<ans[i].start<<"-"<<ans[i].end<<endl;
}
void subdivision(int n,fstream &file)
{
    int temp;
    station data[Maxsize];
    for(int i=0;i<Maxsize&&!file.eof();i++)
        file>>data[i].ENODEBID>>data[i].LONGITUDE>>data[i].LATITUDE>>temp;
    Minweight(n,data);
}
int main()
{
    fstream filedata("21.txt");
    fstream filedata1("29.txt");
    cout<<"第一组边长弦长总和最优值及相连的弦为:";
    subdivision(20,filedata);
    cout<<"第二组边长弦长总和最优值及相连的弦为:";
    subdivision(28,filedata1);
    return 0;
}
