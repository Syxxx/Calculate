/*4-6个数字，5个运算符号,0-3个括号
  四个数字4+3=7位字符串 6+5=11位字符串*/
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
     q=rand()%3+4;   //数字一共多少位
     cout<<q<<endl;
     
     equation(q);
     bracket(e,q,t-1);//注意这里传的是t-1，形参只有一个t 

}

void equation(int t)
{
     char a[]="+-*/";//{'+','*','-','/'};
     int e[20];
	 char q[20];       //算式字符串

     srand((unsigned(time(NULL))));
     for(int i=0;i<t*2-1;i++)
     {
          e[i]=rand()%8+1;    // 数字
          q[i]=a[rand()%4]; //符号
     }
     q[t-1]='=';
     cout<<endl;
	 for(int i=0;i<=t-1;i++) //测试算式
     {
          cout<<e[i]<<q[i];
     }
     cout<<endl;
}

void bracket(int m[],char n[],int t){   //添加括号
     srand((unsigned(time(NULL))));
     int q=rand()%2;    //有几个括号
     cout<<q<<endl;
     if(q==1)
     {
     	srand((unsigned(time(NULL))));
        int a=rand()%(t/2)+1;
        int b=a+rand()%(t/2)+2;//分别在第几个数加括号 
         cout<<a+1<<endl;
         cout<<b<<endl;

          for(int i=0;i<=t;i++) //测试算式
          {
          if(i==a) cout<<"(";
		  cout<<m[i];
		  if(i==b-1) cout<<")";
		  cout<<n[i];
          }
     }
     //a+1是第一个括号的位置，b是第二个括号的位置
	  
}

