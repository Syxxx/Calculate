#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;

void init();
void equation(int t); //产生算式 
void bracket(int m[],char n[],int t); //添加括号 
char nowsign,sign;
int s1[10];
char s2[10];
int k=0,correct=0,wrong=0,flag=0,temp=0,num=0,a,b,lan; 
void match( char nowsign );  //匹配符号 
double low(int t); //加减运算 
double mid(int t); //乘除运算 
double high(int t); //括号及数字 
void check (int t); //运算答案 
void checkanswer(int result); //检验答案 
void initFraction(int t); //真分数运算 
void fraction(int n[20],char s[20]); //真分数运算 
void finally(); //统计结果 


int main(){
	srand((unsigned(time(NULL))));
	int n;
	cout<<"请选择语言(Please choose language)"<<endl;cout<<"1.中文 2.English ： ";
	cin>>lan;
	switch(lan)
	{
		case 1:cout<<"请输入题数：";cin>>n;break;
		case 2:cout<<"Please enter a number of questions：";cin>>n;break;
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
     q=rand()%3+4;   //数字一共多少位
     equation(q);
}
 
void equation(int t) //产生算式 
{
     char c[]="+-*/";//{'+','*','-','/'};
     int e[20];
	 char q[20];       //算式字符串

     for(int i=0;i<t;i++)
     {
          e[i]=rand()%8+1;    // 数字
          q[i]=c[rand()%4]; //符号
     }
     q[t-1]='=';
     bracket(e,q,t-1);//注意这里传的是t-1，形参只有一个t 
}

void bracket(int m[],char n[],int t){   //添加括号
     num=rand()%2;    //有几个括号
     if(num==1)
     {
     	flag=0;
     	temp=0;
        a=rand()%(t/2)+1;
        b=a+rand()%(t/2)+2;//分别在第几个数加括号 
 //a+1是第一个括号的位置，b是第二个括号的位置
        for (int i=0;i<t+1;i++)
     	{
     		s1[i]=m[i];  //数字 
     		s2[i]=n[i];  //符号 
		}
          check(t+1);
     }
     else if(num==0)
     {
		for (int i=0;i<t+1;i++)
     	{
     		s1[i]=m[i];  //数字 
     		s2[i]=n[i];  //符号 
		}
		check(t+1);	
	 }
}
/*s1[i]是m[i],数字，s2[i]是n[i]，符号*/ 
void check (int t)  //运算答案 
{
	double result = 0;
	sign = s1[0]; //载入第一个符号
	result = low(t); //进行计算
	if (result==(int)result)
	{
		if (num==0)
		{
			for (int i=0;i<t;i++)
    		{
     			if (s2[i]=='/')
     			cout<<s1[i]<<"÷";
     			else
     			cout<<s1[i]<<s2[i];
			}
		//	cout<<result;
		}
		else if (num==1)
		{
	    		for(int i=0;i<t;i++) //测试算式
	    		{
	    		    if(i==a) cout<<"(";
					cout<<s1[i];
					if(i==b-1) cout<<")";
					if (s2[i]=='/')
					cout<<"÷";
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

void checkanswer(int result) //检验答案 
{
		int answer;
		char ch;
	    cin>>answer;
	    ch=getchar(); 
		if(answer==result)
	    {
		    if(lan==1)
		    cout<<"     答案正确";
		    else
		    cout<<"     correct";
			correct+=1;
     	}
      	else if ((answer!=result)&&(ch!='e'))
      	{
      		if(lan==1)
	    	cout<<"     答案错误，正确答案为:"<<result;
	    	else
	    	cout<<"     wrong answer. The correct answer is:"<<result;
	    	wrong+=1;
		}
		if (ch=='e')
		{
			finally();
		}
}

void match( char nowsign ) //匹配符号 
{
	if (num==0)
	{
		if( sign == nowsign ) //匹配成功，获取下一个标志
		{
			k++;
			if ((k%2) == 0) //下一位是数字 
			sign = s1[k/2];
			else    //下一位是符号 
			sign = s2[(k-1)/2];
		}
	}
	else if (num==1)
	{
		if( sign == nowsign ) //匹配成功，获取下一个标志
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
			else if (((k%2) == 0)&&(k!=2*a)) //下一位是数字 
			sign = s1[k/2];
			else if (((k%2) != 0)&&(k!=b*2-1))    //下一位是符号 
			sign = s2[(k-1)/2];
		}
	} 

}

double low(int t) //加减运算 
{
	double result1 = mid(t); //计算比加减运算优先级别高的部分
	while(( sign == '+' ) || ( sign == '-' ))
	if ( sign == '+')
	{
		match('+');     //进行加法运算
		result1 += mid(t);
		if (k==2*t-1)
		break;
	}
	else if ( sign == '-')
	{
		match('-');    //进行减法运算
		result1 -= mid(t);
		if (k==2*t-1) 
		break;
	}
	return result1;
}

double mid(int t) //乘除运算 
{
	double result2 = high(t);
		while(( sign == '*' ) || ( sign == '/' ))
	if ( sign == '*')
	{
		match('*');     //进行乘法运算
		result2 *= high(t);
		if (k==2*t-1)
		break;
	}
	else if ( sign == '/')
	{
		match('/');    //进行除法运算
		result2 /= high(t);
		if (k==2*t-1) 
		break;
	}
	return result2;
}


double high(int t) //括号运算及数字 
{
	double result3; 
	if( sign == '(' ) //带有括号的运算
	{
		match( '(' );
		result3 = low(t); //递归计算表达式
		match(')');
	}
	else if (sign >= 0 && sign<= 9) //实际的数字
	{
		result3=sign;
		k++;
		if (num==0)
		{
			sign = s2[(k-1)/2];//下一位是符号 
		}
		else if (num==1)
		{
			if ((k==b*2-1)&&(temp==0))
			{
				sign = ')';
				temp=1;
				k--;
			}
			else if (((k%2) != 0)&&(k!=b*2-1))    //下一位是符号 
			sign = s2[(k-1)/2];
		}

	}
	return result3;
}


void initFraction(int t)
{
     char c[]="+-*/";//{'+','*','-','/'};
     int  n[4];       //数字 
	 char s[2];       //符号 

     for(int i=0;i<4;)
     {
         int x=rand()%9+1;    //有可能是分子分母的两个数 
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
	int demo; //分子
	double nume,result; //分母 
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
	 for(int j=0,i=0;i<4;i++) //测试算式
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
		  	cout<<"÷";
			else 
		  	cout<<s[j];
		  	j++;
		  }
     }
    //cout<<result;
    checkanswer(result);
	}
}

void finally() //统计结果 
{
	if(lan==1)
	cout<<endl<<"做对"<<correct<<"道题;"<<"做错"<<wrong<<"道题";
	else
	cout<<endl<<"Correct questions:"<<correct<<";Wrong questions:"<<wrong; 
	exit(0);
}
