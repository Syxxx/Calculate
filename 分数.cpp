
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
     q=rand()%2+2;   //һ�����ٸ����� 
     cout<<q<<endl;
     equation(q);

}

void equation(int t)
{
     char a[]="+-*/";//{'+','*','-','/'};
     int  n[20];       //���� 
	 char s[20];       //���� 

     srand((unsigned(time(NULL))));
     for(int i=0;i<t*2;)
     {
         int a=rand()%9+1;    //�п����Ƿ��ӷ�ĸ�������� 
         int b=rand()%9+1;  
         if(a!=b)
		 {
		 	  
			  if(a>b)
			  {
			  	n[i]=b;n[i+1]=a;
			  }
			  else
			  {
			  	n[i]=a;n[i+1]=b;
			  }
			  i+=2;
		 } 
     }
     for(int i=0;i<t;i++)
	 {
	 	s[i]=a[rand()%4];
	 	if(i==t-1)
	 	{
	 		s[i]='=';
		}
	 } 
	 
//     q[t-1]='=';
     cout<<endl;
	 for(int j=0,i=0;i<t*2;i++) //������ʽ
     {
          if(i/2.0==i/2)
          {
          	cout<<"(";
		  }
		  cout<<n[i];
		  if(i/2.0!=i/2)
		  {
		  	cout<<")";
		  }
          if(i/2.0==i/2)
          {
          	cout<<"/";
		  }
		  else
		  {
		  	cout<<s[j];
		  	j++;
		  }
     }
     cout<<endl;
     
}
//���ֶ�������n[]�� 

