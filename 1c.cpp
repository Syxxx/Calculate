/*4-6个数字，5个运算符号,0-3个括号
  四个数字4+3=7位字符串 6+5=11位字符串*/
#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;


void init();
void equation(int t);
void bracket(int t);

int main(){
    init();
}

void init(){
     int q;
     srand((unsigned(time(NULL))));
     q=(rand()%2+3)*2+1;   //一共多少位
     cout<<q<<endl;
     equation(q);

}

void equation(int t)
{
     char a[]={'+','×','-','÷'};
     char e[t];        //算式字符串
     //char *s=e;
     srand((unsigned(time(NULL))));
     for(int i=0;i<t;i+=2)
     {
          e[i]=rand()%8+1; cout<<e[i]<<endl;// 数字
          e[i+1]=a[rand()%3];cout<<e[i+1]<<endl;//符号
     }
     for(int i=0;i<t;i++) //测试算式
     {
          cout<<e[i];
     }
     cout<<endl;
     bracket(t);
}

void bracket(int t){   //添加括号
     srand((unsigned(time(NULL))));
     int q=rand()%2;    //有几个括号
     cout<<q<<endl;
     if(q==1)
     {
        int a=rand()%((t-1)/2)*2+1;
        int b=a+2;
         cout<<a<<endl;
          cout<<b<<endl;

     }
     if(q==2)
     {

     }
}
