#include <iostream>

using namespace std;

int max(int *x,int low,int high);
int Max3(int x,int y,int z);

int main()
{
    int x[13]={1,2,3,-3,2,-3,4,-2,3,100,2,-101,3};
    cout<<max(x,0,12)<<endl;
    return 0;
}


int max(int *x,int low,int high){

    cout<<low<<" "<<high<<endl;
    if(low>high) return 0;
    if(low==high) return x[low];
    int mid=(low+high)/2;
    int leftmax=max(x,low,mid);
    int rightmax=max(x,mid+1,high);

    int leftbordermax=0;
    int tempsum=0;
    for(int i=mid;i>=low;i--)
    {
        tempsum+=x[i];
        if(tempsum>leftbordermax)
            leftbordermax=tempsum;
    }
    int rightbordermax=0;
    tempsum=0;
    for(int i=mid+1;i<=high;i++)
    {
        tempsum+=x[i];
        if(tempsum>rightbordermax)
            rightbordermax=tempsum;
    }
    return Max3(leftmax,rightmax,leftbordermax+rightbordermax);
}
int Max3(int x,int y,int z){
    return x>y?x>z?x:z:y>z?y:z;
}
