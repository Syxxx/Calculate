/*4-6�����֣�5���������,0-3������
  �ĸ�����4+3=7λ�ַ��� 6+5=11λ�ַ���*/
#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;


void init();
void equation(int t);
void bracket(int m[],char n[],int t);

int main(){
    init();
}

void init(){
     int q;
     srand((unsigned(time(NULL))));
     q=rand()%3+4;   //����һ������λ
     cout<<q<<endl;
     
     equation(q);
     bracket(e,q,t-1);//ע�����ﴫ����t-1���β�ֻ��һ��t 

}

void equation(int t)
{
     char a[]="+-*/";//{'+','*','-','/'};
     int e[20];
	 char q[20];       //��ʽ�ַ���

     srand((unsigned(time(NULL))));
     for(int i=0;i<t*2-1;i++)
     {
          e[i]=rand()%8+1;    // ����
          q[i]=a[rand()%4]; //����
     }
     q[t-1]='=';
     cout<<endl;
	 for(int i=0;i<=t-1;i++) //������ʽ
     {
          cout<<e[i]<<q[i];
     }
     cout<<endl;
}

void bracket(int m[],char n[],int t){   //�������
     srand((unsigned(time(NULL))));
     int q=rand()%2;    //�м�������
     cout<<q<<endl;
     if(q==1)
     {
     	srand((unsigned(time(NULL))));
        int a=rand()%(t/2)+1;
        int b=a+rand()%(t/2)+2;//�ֱ��ڵڼ����������� 
         cout<<a+1<<endl;
         cout<<b<<endl;

          for(int i=0;i<=t;i++) //������ʽ
          {
          if(i==a) cout<<"(";
		  cout<<m[i];
		  if(i==b-1) cout<<")";
		  cout<<n[i];
          }
     }
     //a+1�ǵ�һ�����ŵ�λ�ã�b�ǵڶ������ŵ�λ��
	  
}

