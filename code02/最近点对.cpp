#include <iostream>
#include <fstream>
#include <cmath>
#define Maxsize 1033
const double EARTH_RADIUS = 6378.137;//赤道半径km
const double INFINIT=10000000000.0;
using namespace std;
typedef struct
{
    int ENODEBID;
    double LONGITUDE,LATITUDE,K_DIST;
} station;
typedef struct
{
    station x,y;
    double d;
} closepair;//最近点对结构
int Partition(station *data,int low,int high,int k)
{
    station temp=data[k];
    while(low<high)
    {
        while(low<high&&data[high].LONGITUDE>=temp.LONGITUDE)
        high--;
        data[low]=data[high];
        while(low<high&&data[low].LONGITUDE<=temp.LONGITUDE)
            low++;
        data[high]=data[low];
    }
    data[low]=temp;
    return low;
}
void quicksort(station *data,int low,int high)
{
    if(low<high)
    {
    int temp=Partition(data,low,high,low);
    quicksort(data,low,temp-1);
    quicksort(data,temp+1,high);
    }
}
//将对应的经纬度转化为弧度
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
    double s=acos(cos(radLat1)*cos(radLat2)*cos(radlng1-radlng2)+sin(radLat1)*sin(radLat2));
    s=s*EARTH_RADIUS*1000;
    return s;
}
closepair mini_distance(station *data,int low,int high)
{
   if(low==high)
    {
        closepair ans;
        ans.x=ans.y=data[low];
        ans.d=INFINIT;
        return ans;
    }
    int m=(low+high)/2;
    closepair ansleft=mini_distance(data,low,m);
    closepair ansright=mini_distance(data,m+1,high);
    if(ansleft.d>ansright.d)  ansleft=ansright;
    station w1[Maxsize],w2[Maxsize];
    int p1=0,p2=0;
    for(int i=low;i<=high;i++)
    {
        station temp;
        temp.LATITUDE=data[i].LATITUDE;
        temp.LONGITUDE=data[m].LONGITUDE;
        if(GetDistance(data[i],temp)<ansleft.d)
        {
         if(i<=m) w1[p1++]=data[i];
         else    w2[p2++]=data[i];
        }
    }
    double lattitudecha=ansleft.d/110940;
    for(int i=0;i<=p1-1;i++)
      for(int j=0;j<=p2-1;j++)
        if(fabs(w2[j].LATITUDE-w1[i].LATITUDE)<=lattitudecha&&GetDistance(w1[i],w2[j])<ansleft.d)
        {
          ansleft.x=w1[i];
          ansleft.y=w2[j];
          ansleft.d=GetDistance(w1[i],w2[j]);
        }
    return ansleft;
}
closepair Secondary_distance(closepair minidistance,station *data)
{
    station data1[Maxsize-1],data2[Maxsize-1];
    for(int i=0,j1=0,j2=0;i<Maxsize;i++)
    {
        if(data[i].ENODEBID!=minidistance.x.ENODEBID) data1[j1++]=data[i];
        if(data[i].ENODEBID!=minidistance.y.ENODEBID) data2[j2++]=data[i];
    }
    closepair ans1=mini_distance(data1,0,Maxsize-2);
    closepair ans2=mini_distance(data2,0,Maxsize-2);
    if(ans1.d>ans2.d) ans1=ans2;
    return ans1;
}
int main()
{
    ifstream filedata("C:\\Users\\lianzhuang\\Desktop\\aaa\\basedata.txt");
    station data[Maxsize];
    for(int i=0;i<Maxsize;i++)
        filedata>>data[i].ENODEBID>>data[i].LONGITUDE>>data[i].LATITUDE>>data[i].K_DIST;
    quicksort(data,0,Maxsize-1);
    closepair ans=mini_distance(data,0,Maxsize-1);
    cout<<ans.x.ENODEBID<<" "<<ans.y.ENODEBID<<" "<<ans.d<<endl;
    closepair ans1=Secondary_distance(ans,data);
    cout<<ans1.x.ENODEBID<<" "<<ans1.y.ENODEBID<<" "<<ans1.d<<endl;
    return 0;
}
