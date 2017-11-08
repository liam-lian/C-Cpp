#include <iostream>

using namespace std;

int quickpass(int *m,int low,int high){
    int flag=m[low];
    while(low<high)
    {
        if(low<high&&m[high]>=flag) high--;
        m[low]=m[high];
        if(low<high&&m[low]<=flag) low++;
        m[high]=m[low];
    }
    m[low]=flag;
    return low;
}

void quicksort(int * m,int low,int high)
{
    if(low<high)
    {
        int pos=quickpass(m,low,high);
        quicksort(m,low,pos-1);
        quicksort(m,pos+1,high);
    }
}


int partion(int *x,int low,int high){

   int temp=x[low];
   int i=low;
   int j=high+1;

   while(true){
     while(x[++i]<temp);
     while(x[--j]>temp);
     if(i>=j) break;
     swap(x[i],x[j]);
   }
   x[low]=x[j];
   x[j]=temp;
   return j;
}

int quickpass1(int *x,int low,int high){
    if(low<high){
        int p=partion(x,low,high);
        quickpass1(x,low,p-1);
        quickpass1(x,p+1,high);
    }
}





void Merge(int *m,int s1,int e1,int e2){
   int s2=e1+1;
   int n[9];
   int i=s1;
   int s=s1;

   while(s1<=e1&&s2<=e2){
    if(m[s1]<=m[s2])
        n[i++]=m[s1++];
    else
        n[i++]=m[s2++];;
   }
            while(s1<=e1)
               n[i++]=m[s1++];
            while(s2<=e2)
               n[i++]=m[s2++];

      for(int i=s;i<=e2;i++)
     {
         m[i]=n[i];
     }
}

void mergesort(int *m,int low,int high){

    cout<<low<<high<<"  "<<endl;

    cout<<endl;
    if(low<high){
        int mid=(low+high)/2;
        mergesort(m,low,mid);
        mergesort(m,mid+1,high);
        Merge(m,low,mid,high);
    }
}
//求第k小的元素
int mink(int *m,int low,int high,int k){


    if(low==high) return m[low];
    int f=partion(m,low,high);
    int lnum=f-low+1;
    if(lnum>=k)
       return mink(m,low,f,k);
    else
       return mink(m,f+1,high,k-lnum);
}

int main()
{
    int a[9]={1,4,3,12,355,2,11,22,33};
    //quicksort(a,0,8);
    //mergesort(a,0,8);
    quickpass1(a,0,8);
    for(int i=0;i<9;i++) cout<<a[i]<<" ";

    cout<<mink(a,0,8,5);
    return 0;
}
