//�����ݣ��������ͣ�ƽ��ֵ����λ��������������ӡƵ��ֱ��ͼ 
#include <stdio.h>
#include <stdlib.h>
void printarray(int a[],int num);
void Paixu(int a[],int num);
int main(int argc, char *argv[])
{
    int i,a[100]={0},Pinshu[100]={0},c[100],num=0,j,sum=0,p=1,max=0,q,isok=1;
    float mid;
    printf("���������ݣ���-1������");
    for(i=0;i<=99&&a[i-1]!=-1;i++)//ע��i-1 
        {
           scanf("%d",&a[i]);
           if(a[i]!=-1)
              {
                sum=sum+a[i];
                num++;
              }
         }                                         //��ȡ���ݣ����������ݸ��� 
    printf("����������%d�����ݣ����Ϊ%d��ƽ����Ϊ%.2f\n��%d�����ֱ�Ϊ\n",num,sum,(float)sum/num,num);
    printarray(a,num);                            //���� 
    printf("�����򣬽��Ϊ��\n");
    Paixu(a,num);                             //��ӡ���� 
    mid=num%2==0?(float)(a[num/2]+a[num/2-1])/2:(float)a[num/2];//����λ�� 
    printf("��λ��Ϊ��%.2f\nͳ��ֱ��ͼΪ:\n",mid);
      c[0]=a[0]; 
    for(i=1;i<=num-1;i++)                  //�ҳ����г��ֹ������֣�����c        
      {
          for(j=0;j<i&&isok==1;j++)
            {
                if(a[i]==a[j])
                isok=0;
            }
          if(isok==1)
            {
                 c[p]=a[i];
                 p++;
            }
          isok=1;             //ע���ʼ�� 
      }
     for(i=0;i<=num;i++)
        for(j=0;j<=p-1;j++)
               if(a[i]==c[j])
                     Pinshu[j]++;//�����Ƶ�� 
    printf("%-8s%-8s%-8s\n","����","����","ֱ��ͼ");
    for(i=0;i<=p-1;i++)
        {
            printf("%-8d%-8d",c[i],Pinshu[i]);
            for(j=1;j<=Pinshu[i];j++)
              printf("%c",1);
            printf("\n");  
        }     
    for(i=0;i<=p;i++)      // ������ 
        if(Pinshu[i]>max)
          {
             max=Pinshu[i];
             q=c[i];
          }
    printf("%d ",q);      
    for(i=q;i<=p;i++)
       if(Pinshu[i]==max)
          printf("%d ",c[i]);//���Ƕ������ 
    printf("Ϊ������������%d��\n",max);
    system("PAUSE");	
    return 0;
}
void printarray(int array[],int num)//��ӡ���顣8��һ�� 
{
     int i;
     for(i=0;i<=num-1;i++)
        {
           printf("%d ",array[i]);
           if((i+1)%8==0)
              printf("\n");
        }
         printf("\n");
}   
void Paixu(int a[],int n)//�������� 
{
     int i,j,k;
     for(i=0;i<=n-2;i++)
       for(j=i+1;j<=n-1;j++)
            if(a[i]>a[j])
              {
                 k=a[i];
                 a[i]=a[j];
                 a[j]=k;
              }
     printarray(a,n);
}                                                
