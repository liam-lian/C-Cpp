#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<time.h>
using namespace std;
#define Maxnum 10000000
double bestw=1000000;
typedef struct Travel{
	int station[50];//��վ��
	int n;//ͼ�Ķ�����
	int m;//��ʼ���� ���
	double a[50][50];//ͼ���ڽӾ���
	int	x[50] ;//��ǰ��
	int sum;//�ѷ��ʽ����
}Travel;
void read_file3(int ele[],double c[][50],int all)//��ȡ����
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
	getline(file,str,'\n');//����һ��
	for(int i=1;i<=all;i++)
	{
		file>>num;//�����б�־
		for(int j=1;j<=all;j++)
		{
			file>>num;
			c[i][j]=num;
		}
		getline(file,str,'\n');//����һ��
	}
	file.close();
	}

	else {
		ifstream file("����1-1.42-ͼ���ڽӾ���.txt");
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
	getline(file,str,'\n');//����һ��

	for(int i=1;i<=all;i++)
	{
		file>>num;//�����б�־

		for(int j=1;j<=all;j++)
		{
		    file>>num;
			c[i][j]=num;

		}
		getline(file,str,'\n');//����һ��
	}
	file.close();
	}
}
double w1(int p,int q,double c[][50])//�ж��������Ƿ�Ϊ���ڵ㲢���ؾ���
{
	return c[p][q];
}

void BacktrackTSP(int i,double cw,int bestx[],int x[],int n,double c[][50])
{
  if  (i==n)     //�Ѿ�������Ҷ�ڵ㣬�Ѿ�ѡ�������1������
 {
    //cout<<"aaa"<<x[n]<<endl<<x[i];
        if ( w1(x[n-1], x[n],c) !=-1 && w1(x[n],x[1],c )!=-1)  //�Ƚϵ�ǰ��·����ǰ��ѻ�·������ǰ��·�Ƿ����
              {
              	if( (cw + w1(x[n-1],x[n],c) + w1(x[n],x[1] ,c))< bestw)
                        {      //��ǰ��·���ţ����������������
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
     //�������û�е�Ҷ�ڵ�, ��ǰ�õ��Ĳ���·��
        {
    for (int j=i;j<=n;j++)   //����x[i]�ĸ�������ȡֵ
            {
            if( w1(x[i-1],x[j],c)!=-1 && (cw + w1(x[i-1], x[j],c))< bestw)
                //������չ��������·��
                {
                            swap(x[i],x[j]);        //�����i������
                            cw = cw + w1(x[i-1],x[i],c); //������չ���·���Ĵ���
                            BacktrackTSP(i+1,cw,bestx,x,n,c);      //�ݹ�������x[i]Ϊ���� ��������
                            cw = cw-w1(x[i-1],x[i],c); //����ʧ�ܣ����ݣ��ص���9����Ϊ����x[i]����һ��ȡֵx[j+1]׼��
                            swap(x[i],x[j]);
                }
            }
        }//end else
}
void backtrack(int x[],int n,int ele[])
{
	cout<<x[0]<<"�� "<<ele[x[0]]<<"\t";
	for(int i=1;i<=n;i++)
	{
		cout<<x[i]<<"�� "<<ele[x[i]]<<"\t";
	}
	cout<<x[0]<<"�� "<<ele[x[0]]<<"\t";
	cout<<bestw;
    cout<<endl;
}
int main()
{

	int choose;
	cout<<"���������������밴1���˳��밴0\n";
	cin>>choose;
	while(choose)
  {
  		clock_t start, finish;
	    start = clock();
  	    Travel travel;
  	    cout<<"������ͼ�Ķ���������ʼ���У��Կո����\n";
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
       BacktrackTSP(2, cw,bestx,x,travel.n,travel.a);//cwΪ�������Ž⣬bestwΪ��ǰ���Ž�

	   backtrack(bestx,travel.n,travel.station);
	   cout<<"���������������밴1���˳��밴0\n";
   	   cin>>choose;
  }
  return 0;
}
