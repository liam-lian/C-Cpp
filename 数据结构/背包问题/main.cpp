#include <iostream>

/*
 a[i][j]=max{a[i-1][j-weight[i]]+value[i],a[i-1][j]}
 出口条件
 i>=0;
 j-wight>0;
 要求的是a[len-1][total]
*/
using namespace std;

int _01packet(int *weight,int* value,int i,int j){
    if(i<0) return 0;
    if(j-weight[i]>=0)
      return max(_01packet(weight,value,i-1,j-weight[i])+value[i],_01packet(weight,value,i-1,j));
    else
      return  _01packet(weight,value,i-1,j);
}



int main()
{
    int weight[8]={79,58,86,11,28,62,15,68};
    int value[8]={83,14,54,79,72,52,48,62};
    cout << _01packet(weight,value,7,200) << endl;
    return 0;
}
