/*4-6�����֣�5���������,0-3������
  �ĸ�����4+3=7λ�ַ��� 6+5=11λ�ַ���*/
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
     q=(rand()%2+3)*2+1;   //һ������λ
     cout<<q<<endl;
     equation(q);

}

void equation(int t)
{
     char a[]={'+','��','-','��'};
     char e[t];        //��ʽ�ַ���
     //char *s=e;
     srand((unsigned(time(NULL))));
     for(int i=0;i<t;i+=2)
     {
          e[i]=rand()%8+1; cout<<e[i]<<endl;// ����
          e[i+1]=a[rand()%3];cout<<e[i+1]<<endl;//����
     }
     for(int i=0;i<t;i++) //������ʽ
     {
          cout<<e[i];
     }
     cout<<endl;
     bracket(t);
}

void bracket(int t){   //�������
     srand((unsigned(time(NULL))));
     int q=rand()%2;    //�м�������
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
