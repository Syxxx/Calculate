#include "stdafx.h"
#include "operate.h"
#include "equation.h"
#include "Message.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

operate::operate()
{}

void operate::match(char nowsign) //匹配符号 
{
	Message msg;
	if (msg.bracket_num == 0)
	{
		if (sign == nowsign) //匹配成功，获取下一个标志
		{
			k++;
			if ((k % 2) == 0) //下一位是数字 
				sign = msg.s1[k / 2];
			else    //下一位是符号 
				sign = msg.s2[(k - 1) / 2];
		}
	}
	else if (msg.bracket_num == 1)
	{
		if (sign == nowsign) //匹配成功，获取下一个标志
		{
			k++;
			if ((k == 2 * msg.bracket_a) && (flag == 0))
			{
				sign = '(';
				flag = 1;
				k--;
			}
			else if ((k == msg.bracket_b * 2 - 1) && (temp == 0))
			{
				sign = ')';
				temp = 1;
				k--;
			}
			else if ((k == 2 * msg.bracket_a) && (flag == 1))
				sign = msg.s1[k / 2];
			else if ((k == msg.bracket_b * 2 - 1) && (temp == 1))
				sign = msg.s2[(k - 1) / 2];
			else if (((k % 2) == 0) && (k != 2 * msg.bracket_a)) //下一位是数字 
				sign = msg.s1[k / 2];
			else if (((k % 2) != 0) && (k != msg.bracket_b * 2 - 1))    //下一位是符号 
				sign = msg.s2[(k - 1) / 2];
		}
	}

}

double operate::low() //加减运算 
{
	Message msg;
	double result1 = mid(); //计算比加减运算优先级别高的部分
	while ((sign == '+') || (sign == '-'))
		if (sign == '+')
		{
			match('+');     //进行加法运算
			result1 += mid();
			if (k == 2 * msg.digit_num - 1)
				break;
		}
		else if (sign == '-')
		{
			match('-');    //进行减法运算
			result1 -= mid();
			if (k == 2 * msg.digit_num - 1)
				break;
		}
	return result1;
}

double operate::mid() //乘除运算 
{
	Message msg;
	double result2 = high();
	while ((sign == '*') || (sign == '/'))
		if (sign == '*')
		{
			match('*');     //进行乘法运算
			result2 *= high();
			if (k == 2 * msg.digit_num - 1)
				break;
		}
		else if (sign == '/')
		{
			match('/');    //进行除法运算
			result2 /= high();
			if (k == 2 * msg.digit_num - 1)
				break;
		}
	return result2;
}


double operate::high() //括号运算及数字 
{
	Message msg;
	double result3 = 0;
	if (sign == '(') //带有括号的运算
	{
		match('(');
		result3 = low(); //递归计算表达式
		match(')');
	}
	else if (sign >= 0 && sign <= 9) //实际的数字
	{
		result3 = sign;
		k++;
		if (msg.bracket_num == 0)
		{
			sign = msg.s2[(k - 1) / 2];//下一位是符号 
		}
		else if (msg.bracket_num == 1)
		{
			if ((k == msg.bracket_b * 2 - 1) && (temp == 0))
			{
				sign = ')';
				temp = 1;
				k--;
			}
			else if (((k % 2) != 0) && (k != msg.bracket_b * 2 - 1))    //下一位是符号 
				sign = msg.s2[(k - 1) / 2];
		}

	}
	return result3;
}

void operate::check()  //运算答案 
{
	Message msg;
	equation equ;
	sign = msg.s1[0]; //载入第一个符号
	msg.result = low(); //进行计算

	if (msg.result == (int)msg.result)
	{
		if (msg.bracket_num == 0)
		{
			for (int i = 0;i < msg.digit_num;i++)
			{
				if (msg.s2[i] == '/')
					cout << msg.s1[i] << "÷";
				else
					cout << msg.s1[i] << msg.s2[i];
			}
			//cout<<msg.result;
		}
		else if (msg.bracket_num == 1)
		{
			for (int i = 0;i < msg.digit_num ; i++) //测试算式
			{
				if (i == msg.bracket_a) cout << "(";
				cout << msg.s1[i];
				if (i == msg.bracket_b - 1) cout << ")";
				if (msg.s2[i] == '/')
					cout << "÷";
				else
					cout << msg.s2[i];
			}
			//		cout<<msg.result; 
		}
		equ.checkanswer(msg.result);
	}
	else if (msg.result != (int)msg.result)
	{
		k = 0;
		equ.initequation();
	}
}




