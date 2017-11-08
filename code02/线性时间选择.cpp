#include <iostream>
#include <fstream>
#define Maxsize 1033
using namespace std;
typedef struct
{
    int ENODEBID;
    float LONGITUDE,LATITUDE,K_DIST;
} station;
int Partition(station *data,int low,int high,int k)
{
    station temp=data[k];
    while(low<high)
    {
        while(low<high&&data[high].K_DIST>=temp.K_DIST) high--;
        data[low]=data[high];
        while(low<high&&data[low].K_DIST<=temp.K_DIST) low++;
        data[high]=data[low];
    }
    data[low]=temp;
    return low;
}
int  liner_time_select(station *data,int low,int high,int k)
{
      if (low==high) return low;
      int i=Partition(data,low,high,low);
      int j=i-low+1;
      if (k<=j) return liner_time_select(data,low,i,k);
      else return liner_time_select(data,i+1,high,k-j);
}
int main()
{
    ifstream filedata("C:\\Users\\lianzhuang\\Desktop\\aaa\\basedata.txt");
    station data[Maxsize];
    for(int i=0;i<Maxsize;i++)
        filedata>>data[i].ENODEBID>>data[i].LONGITUDE>>data[i].LATITUDE>>data[i].K_DIST;
    cout<<data[liner_time_select(data,0,Maxsize-1,1)].ENODEBID<<endl;
    cout<<data[liner_time_select(data,0,Maxsize-1,5)].ENODEBID<<endl;
    cout<<data[liner_time_select(data,0,Maxsize-1,50)].ENODEBID<<endl;
    cout<<data[liner_time_select(data,0,Maxsize-1,Maxsize)].ENODEBID<<endl;
    return 0;
}
