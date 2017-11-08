#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

int maxcom(char *X,char *Y,int Xlen,int Ylen)
{
    if(Xlen==0||Ylen==0) return 0;
    if(X[Xlen]==Y[Ylen]) return maxcom(X,Y,Xlen-1,Ylen-1)+1;
    else
        return max(maxcom(X,Y,Xlen,Ylen-1),maxcom(X,Y,Xlen-1,Ylen));
}
