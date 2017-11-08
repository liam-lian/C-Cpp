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
void quicksort(station *data,int low,int high)
{
    if(low<high)
    {
    int temp=Partition(data,low,high,low);
    quicksort(data,low,temp-1);
    quicksort(data,temp+1,high);
    }
}
int main()
{
    ifstream filedata("C:\\Users\\lianzhuang\\Desktop\\aaa\\basedata.txt");
    ofstream outfile("quicksort.txt");
    station data[Maxsize];
    for(int i=0;i<Maxsize;i++)
        filedata>>data[i].ENODEBID>>data[i].LONGITUDE>>data[i].LATITUDE>>data[i].K_DIST;
    quicksort(data,0,Maxsize-1);
    for(int i=0;i<Maxsize;i++)
       outfile<<i<<" "<<data[i].ENODEBID<<" "<<data[i].LONGITUDE<<" "<<data[i].LATITUDE<<" "<<data[i].K_DIST<<endl;
    return 0;
}
