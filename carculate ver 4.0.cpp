#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;

void init();
void equation(int t); //������ʽ 
void bracket(int m[],char n[],int t); //������� 
char nowsign,sign;
int s1[10];
char s2[10];
int k=0,correct=0,wrong=0,flag=0,temp=0,num=0,a,b,lan; 
void match( char nowsign );  //ƥ����� 
double low(int t); //�Ӽ����� 
double mid(int t); //�˳����� 
double high(int t); //���ż����� 
void check (int t); //����� 
void checkanswer(int result); //����� 
void initFraction(int t); //��������� 
void fraction(int n[20],char s[20]); //��������� 
void finally(); //ͳ�ƽ�� 


int main(){
	srand((unsigned(time(NULL))));
	int n;
	cout<<"��ѡ������(Please choose language)"<<endl;cout<<"1.���� 2.English �� ";
	cin>>lan;
	switch(lan)
	{
		case 1:cout<<"������������";cin>>n;break;
		case 2:cout<<"Please enter a number of questions��";cin>>n;break;
		defaul:cout<<"Error!";break; 
	}
	for (int j=0;j<n;j++)
	{
		int judge=rand()%5;
		if (judge!=0) 
		init();
		else
		initFraction(2);
		cout<<endl;
	}
	finally();
    return 0;
}

void init(){
	 k=0;
     int q;
     q=rand()%3+4;   //����һ������λ
     equation(q);
}
 
void equation(int t) //������ʽ 
{
     char c[]="+-*/";//{'+','*','-','/'};
     int e[20];
	 char q[20];       //��ʽ�ַ���

     for(int i=0;i<t;i++)
     {
          e[i]=rand()%8+1;    // ����
          q[i]=c[rand()%4]; //����
     }
     q[t-1]='=';
     bracket(e,q,t-1);//ע�����ﴫ����t-1���β�ֻ��һ��t 
}

void bracket(int m[],char n[],int t){   //�������
     num=rand()%2;    //�м�������
     if(num==1)
     {
     	flag=0;
     	temp=0;
        a=rand()%(t/2)+1;
        b=a+rand()%(t/2)+2;//�ֱ��ڵڼ����������� 
 //a+1�ǵ�һ�����ŵ�λ�ã�b�ǵڶ������ŵ�λ��
        for (int i=0;i<t+1;i++)
     	{
     		s1[i]=m[i];  //���� 
     		s2[i]=n[i];  //���� 
		}
          check(t+1);
     }
     else if(num==0)
     {
		for (int i=0;i<t+1;i++)
     	{
     		s1[i]=m[i];  //���� 
     		s2[i]=n[i];  //���� 
		}
		check(t+1);	
	 }
}
/*s1[i]��m[i],���֣�s2[i]��n[i]������*/ 
void check (int t)  //����� 
{
	double result = 0;
	sign = s1[0]; //�����һ������
	result = low(t); //���м���
	if (result==(int)result)
	{
		if (num==0)
		{
			for (int i=0;i<t;i++)
    		{
     			if (s2[i]=='/')
     			cout<<s1[i]<<"��";
     			else
     			cout<<s1[i]<<s2[i];
			}
		//	cout<<result;
		}
		else if (num==1)
		{
	    		for(int i=0;i<t;i++) //������ʽ
	    		{
	    		    if(i==a) cout<<"(";
					cout<<s1[i];
					if(i==b-1) cout<<")";
					if (s2[i]=='/')
					cout<<"��";
					else
					cout<<s2[i];
	    		}
		//		cout<<result; 
		} 
		checkanswer(result);
	} 
	else if (result!=(int)result)
	init();
}

void checkanswer(int result) //����� 
{
		int answer;
		char ch;
	    cin>>answer;
	    ch=getchar(); 
		if(answer==result)
	    {
		    if(lan==1)
		    cout<<"     ����ȷ";
		    else
		    cout<<"     correct";
			correct+=1;
     	}
      	else if ((answer!=result)&&(ch!='e'))
      	{
      		if(lan==1)
	    	cout<<"     �𰸴�����ȷ��Ϊ:"<<result;
	    	else
	    	cout<<"     wrong answer. The correct answer is:"<<result;
	    	wrong+=1;
		}
		if (ch=='e')
		{
			finally();
		}
}

void match( char nowsign ) //ƥ����� 
{
	if (num==0)
	{
		if( sign == nowsign ) //ƥ��ɹ�����ȡ��һ����־
		{
			k++;
			if ((k%2) == 0) //��һλ������ 
			sign = s1[k/2];
			else    //��һλ�Ƿ��� 
			sign = s2[(k-1)/2];
		}
	}
	else if (num==1)
	{
		if( sign == nowsign ) //ƥ��ɹ�����ȡ��һ����־
		{
			k++;
			if ((k==2*a)&&(flag==0)) 
			{
				sign = '(';
				flag=1;
				k--;
			}
			else if ((k==b*2-1)&&(temp==0))
			{
				sign = ')';
				temp=1;
				k--;
			}
			else if ((k==2*a)&&(flag==1))
			sign = s1[k/2];
			else if ((k==b*2-1)&&(temp==1))
			sign = s2[(k-1)/2];		
			else if (((k%2) == 0)&&(k!=2*a)) //��һλ������ 
			sign = s1[k/2];
			else if (((k%2) != 0)&&(k!=b*2-1))    //��һλ�Ƿ��� 
			sign = s2[(k-1)/2];
		}
	} 

}

double low(int t) //�Ӽ����� 
{
	double result1 = mid(t); //����ȼӼ��������ȼ���ߵĲ���
	while(( sign == '+' ) || ( sign == '-' ))
	if ( sign == '+')
	{
		match('+');     //���мӷ�����
		result1 += mid(t);
		if (k==2*t-1)
		break;
	}
	else if ( sign == '-')
	{
		match('-');    //���м�������
		result1 -= mid(t);
		if (k==2*t-1) 
		break;
	}
	return result1;
}

double mid(int t) //�˳����� 
{
	double result2 = high(t);
		while(( sign == '*' ) || ( sign == '/' ))
	if ( sign == '*')
	{
		match('*');     //���г˷�����
		result2 *= high(t);
		if (k==2*t-1)
		break;
	}
	else if ( sign == '/')
	{
		match('/');    //���г�������
		result2 /= high(t);
		if (k==2*t-1) 
		break;
	}
	return result2;
}


double high(int t) //�������㼰���� 
{
	double result3; 
	if( sign == '(' ) //�������ŵ�����
	{
		match( '(' );
		result3 = low(t); //�ݹ������ʽ
		match(')');
	}
	else if (sign >= 0 && sign<= 9) //ʵ�ʵ�����
	{
		result3=sign;
		k++;
		if (num==0)
		{
			sign = s2[(k-1)/2];//��һλ�Ƿ��� 
		}
		else if (num==1)
		{
			if ((k==b*2-1)&&(temp==0))
			{
				sign = ')';
				temp=1;
				k--;
			}
			else if (((k%2) != 0)&&(k!=b*2-1))    //��һλ�Ƿ��� 
			sign = s2[(k-1)/2];
		}

	}
	return result3;
}


void initFraction(int t)
{
     char c[]="+-*/";//{'+','*','-','/'};
     int  n[4];       //���� 
	 char s[2];       //���� 

     for(int i=0;i<4;)
     {
         int x=rand()%9+1;    //�п����Ƿ��ӷ�ĸ�������� 
         int y=rand()%9+1;  
         if(x!=y)
		 {
		 	  
			  if(x>y)
			  {
			  	n[i]=y;n[i+1]=x;
			  }
			  else
			  {
			  	n[i]=x;n[i+1]=y;
			  }
			  i+=2;
		 } 
     }
	s[0]=c[rand()%4];
	s[1]='=';
	 fraction(n,s);    
}
void fraction(int n[4],char s[2])
{
	int demo; //����
	double nume,result; //��ĸ 
	demo=n[1]*n[3];
	n[0]*=n[3];
	n[2]*=n[1];
	switch (s[0])
	{
		case '+':nume=n[0]+n[2];break;
		case '-':nume=n[0]-n[2];break;
		case '*':nume=n[0]*n[2]/n[3]/n[1];break;
		case '/':nume=(double)n[0]/(double)n[2];break;
	}
	result=nume/(double)demo;
	if (result!=(int)result)
	initFraction(2);
	else
	{
	n[0]/=n[3];
	n[2]/=n[1];
	 for(int j=0,i=0;i<4;i++) //������ʽ
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
		  	if (s[j]=='/')
		  	cout<<"��";
			else 
		  	cout<<s[j];
		  	j++;
		  }
     }
    //cout<<result;
    checkanswer(result);
	}
}

void finally() //ͳ�ƽ�� 
{
	if(lan==1)
	cout<<endl<<"����"<<correct<<"����;"<<"����"<<wrong<<"����";
	else
	cout<<endl<<"Correct questions:"<<correct<<";Wrong questions:"<<wrong; 
	exit(0);
}
