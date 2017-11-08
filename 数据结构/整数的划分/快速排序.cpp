
#include <iostream>

using namespace std;

int partion(int *x,int low,int high){

   if(low>=high) return low;
   int temp=x[low];
   int i=low;
   int j=high-1;

   while(true){
     while(x[++i]<temp);
     while(x[--j]>temp);
     if(i>j) break;
     swap(x[i],x[j]);
   }
   x[low]=x[j];
   x[j]=temp;
}

int quickpass(int *x,int low,int high){
    if(low<high){
        int p=partion(x,low,high);
        quickpass(x,low,p-1);
        quickpass(x,p+1,high);
    }
}

