// caculator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "equation.h"
#include "Fraction.h"
#include "operate.h"
#include "Message.h"
#include <time.h>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	Fraction fra;
	equation equ;
	Message msg;

	srand((unsigned(time(NULL))));
	int n;
	cout << "请选择语言(Please choose language)" << endl;cout << "1.中文 2.English ： ";
	cin >> msg.lan;
	switch (msg.lan)
	{
	case 1:cout << "请输入题数：";cin >> n;break;
	case 2:cout << "Please enter a number of questions：";cin >> n;break;
	defaul:cout << "Error!";break;
	}
	for (int j = 0;j<n;j++)
	{	
		msg.clean();
		int judge = rand() % 5;//出现分数运算的几率，目前1/5
		if (judge != 0)
		{   
		   equ.initequation();
		}
		else
		{
			fra.initFraction();
		}
		cout << endl;
	}

	equ.finally();
	return 0;
	
}

