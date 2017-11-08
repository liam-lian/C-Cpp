#include <iostream>

int xzzz=0;
using namespace std;
bool isok(int *matrix,int line,int value){
    for(int i=0;i<line;i++)
    {
       if(matrix[i]==value||matrix[i]-value==line-i||value-matrix[i]==line-i)
        return false;
    }

   return true;
}


void h(int *matrix,int line){
   if(line==7)
   {
       for(int i=0;i<8;i++)
        if(isok(matrix,line,i))
       {
           xzzz++;
           matrix[line]=i;

           for(int i=0;i<8;i++)
           {
               for(int j=0;j<8;j++)
               if(matrix[i]!=j) cout<<0<<" ";
               else cout<<1<<" ";
               cout<<endl;
           }
           cout<<endl;
       }
       return;
   }
   for(int i=0;i<8;i++)
   {
        if(isok(matrix,line,i))
        {
            matrix[line]=i;
            h(matrix,line+1);
        }
   }
}



int main()
{
    int matrix[8];
    h(matrix,0);
    cout<<xzzz;
    return 0;
}
