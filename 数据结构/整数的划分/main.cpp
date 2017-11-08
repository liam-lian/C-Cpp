#include <iostream>

using namespace std;

int q(int m,int n){
   if(n==1) return 1;
   if(m>n) return q(m,n-1)+q(m-n,n);
   if(m<n) return q(m,m);
   if(m==n)
    {
        cout<<n;
        return 1+q(n,n-1);
    }
}

int main()
{
    cout<<q(6,6);
}

