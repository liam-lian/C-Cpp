#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<time.h>
using namespace std;
#define Maxnum 10000000
double bestw=1000000;
typedef struct Travel{
	int station[50];//基站号
	int n;//图的顶点数
	int m;//起始城市 序号
	double a[50][50];//图的邻接矩阵
	int	x[50] ;//当前解
	int sum;//已访问结点数
}Travel;
void read_file3(int ele[],double c[][50],int all)//读取数据
{
	if(all==22)
	{
		ifstream file("22.txt");

	if(!file){
		cerr<<"ERROE"<<endl;
//		exit(-1);
	}
	double num;
	for(int i=1;i<=all;i++)
	{
		file>>ele[i];
	}
	string str;
	getline(file,str,'\n');//过滤一行
	for(int i=1;i<=all;i++)
	{
		file>>num;//过滤行标志
		for(int j=1;j<=all;j++)
		{
			file>>num;
			c[i][j]=num;
		}
		getline(file,str,'\n');//过滤一行
	}
	file.close();
	}

	else {
		ifstream file("附件1-1.42-图的邻接矩阵.txt");
		if(!file){
		cerr<<"ERROE"<<endl;
//		exit(-1);
	}
	double num;

	for(int i=1;i<=all;i++)
	{
		file>>ele[i];


	}
	string str;
	getline(file,str,'\n');//过滤一行

	for(int i=1;i<=all;i++)
	{
		file>>num;//过滤行标志

		for(int j=1;j<=all;j++)
		{
		    file>>num;
			c[i][j]=num;

		}
		getline(file,str,'\n');//过滤一行
	}
	file.close();
	}
}
double w1(int p,int q,double c[][50])//判断两个点是否为相邻点并返回距离
{
	return c[p][q];
}

void BacktrackTSP(int i,double cw,int bestx[],int x[],int n,double c[][50])
{
  if  (i==n)     //已经搜索到叶节点，已经选择了最后1个城市
 {
    //cout<<"aaa"<<x[n]<<endl<<x[i];
        if ( w1(x[n-1], x[n],c) !=-1 && w1(x[n],x[1],c )!=-1)  //比较当前回路与以前最佳回路，看当前回路是否更优
              {
              	if( (cw + w1(x[n-1],x[n],c) + w1(x[n],x[1] ,c))< bestw)
                        {      //当前回路更优，更新最优搜索结果
                              bestw = cw + w1(x[n-1],x[n],c) + w1(x[n],x[1],c) ;
                              for (int j=1 ;j<= n;j++)  {
                              	bestx[j]=x[j];
                              	cout<<x[j]<<" ";
                              }
                              printf("\n");
                        }
               }
      return;
 }
     //如果搜索没有到叶节点, 当前得到的部分路径
        {
    for (int j=i;j<=n;j++)   //考察x[i]的各个可能取值
            {
            if( w1(x[i-1],x[j],c)!=-1 && (cw + w1(x[i-1], x[j],c))< bestw)
                //继续扩展、搜索次路径
                {
                            swap(x[i],x[j]);        //加入第i个城市
                            cw = cw + w1(x[i-1],x[i],c); //更新扩展后的路径的代价
                            BacktrackTSP(i+1,cw,bestx,x,n,c);      //递归搜索以x[i]为根的 后续子树
                            cw = cw-w1(x[i-1],x[i],c); //搜索失败，回溯，回到第9步，为搜索x[i]的另一个取值x[j+1]准备
                            swap(x[i],x[j]);
                }
            }
        }//end else
}
void backtrack(int x[],int n,int ele[])
{
	cout<<x[0]<<"： "<<ele[x[0]]<<"\t";
	for(int i=1;i<=n;i++)
	{
		cout<<x[i]<<"： "<<ele[x[i]]<<"\t";
	}
	cout<<x[0]<<"： "<<ele[x[0]]<<"\t";
	cout<<bestw;
    cout<<endl;
}
int main()
{

	int choose;
	cout<<"测试旅行商问题请按1，退出请按0\n";
	cin>>choose;
	while(choose)
  {
  		clock_t start, finish;
	    start = clock();
  	    Travel travel;
  	    cout<<"请输入图的顶点数和起始城市，以空格隔开\n";
  	    cin>>travel.n>>travel.m;
  	    read_file3(travel.station,travel.a,travel.n);
  	   // for(int i=1;i<=travel.n;i++)
  	     // for(int j=1;j<=travel.n;j++)
  	     //    cout<<travel.a[i][j] <<"\t";
  	         double cw=0;
  	         int bestx[50];
  	         int x[50];


        for(int k=1;k<=travel.n;k++)x[k]=k;
        x[1]=travel.m;
        x[travel.m]=1;
       BacktrackTSP(2, cw,bestx,x,travel.n,travel.a);//cw为部分最优解，bestw为当前最优解

	   backtrack(bestx,travel.n,travel.station);
	   cout<<"测试旅行商问题请按1，退出请按0\n";
   	   cin>>choose;
  }
  return 0;
}
