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
int p=1;
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
void trackback(Edge *v,int n,station *data)
{
    ofstream file2("z.txt");
for(int i=1;i<=n;i++)
    file2<<"g"<<p++<<"=ListPlot[{{"<<data[v[i].start].LONGITUDE<<","<<data[v[i].start].LATITUDE<<"},{"
         <<data[v[i].end].LONGITUDE<<","<<data[v[i].end].LATITUDE<<"}},PlotJoined -> True];"<<endl;
}
void Minweight(int n,station *data)
{
    Edge v[Maxsize],ans[Maxsize];
    int cou=1;
    for(int i=0;i<=n-1;i++)
    {
        v[i].start=i;
        v[i].end=(i+2)%n;
        v[i].enable=1;
        v[i].dist=GetDistance(data[i],data[v[i].end]);
    }
    for(int i=1;i<=n-3;i++)
    {
        int dele=miniedge(v,n-1);
        v[(dele+1)%n].enable=0;
        ans[cou++]=v[dele];
        v[(dele-1+n)%n].end=(v[(dele-1+n)%n].end+1)%n;
        v[(dele-1+n)%n].dist=GetDistance(data[(dele-1+n)%n],data[v[(dele-1+n)%n].end]);
        v[dele].end=(v[dele].end+1)%n;
        v[dele].dist=GetDistance(data[dele],data[v[dele].end]);
    }
    for(int i=1;i<=n-3;i++)
      cout<<ans[i].start<<" "<<ans[i].end<<endl;
      trackback(v,n-3,data);
}

int main()
{
    fstream filedata("C:\\Users\\lianzhuang\\Desktop\\mm.txt");
    int temp;
    station data[Maxsize];
    for(int i=0;i<Maxsize&&!filedata.eof();i++)
        filedata>>data[i].ENODEBID>>data[i].LONGITUDE>>data[i].LATITUDE>>temp;
    Minweight(20,data);
    return 0;
}
