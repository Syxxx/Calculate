#include "stdafx.h"
#include "equation.h"
#include "Operate.h"
#include "Message.h"
#include "Interface.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

const char c[] = "+-*/";

equation::equation()
{}

void equation::initequation()
{
	Message msg;
	msg.digit_num = rand() % 3 + 4;

	for (int i = 0;i < msg.digit_num;i++)
	{
		m[i] = rand() % 8 + 1;
		n[i] = c[rand() % 4];
	}
	n[msg.digit_num - 1] = '=';
	bracket();
}

void equation::bracket() {
	Operate ope;
	Message msg;

	msg.bracket_num = rand() % 2;


	if (msg.bracket_num == 1)
	{
		msg.bracket_a = rand() % ((msg.digit_num - 1) / 2) + 1;
		msg.bracket_b = msg.bracket_a + rand() % ((msg.digit_num - 1) / 2) + 2;

		for (int i = 0; i < msg.digit_num; i++)
		{
			msg.s1[i] = m[i];  //Êý×Ö 
			msg.s2[i] = n[i];  //·ûºÅ 
		}
		ope.check();
	}
	else if (msg.bracket_num == 0)
	{
		for (int i = 0; i < msg.digit_num; i++)
		{
			msg.s1[i] = m[i];  //Êý×Ö 
			msg.s2[i] = n[i];  //·ûºÅ 
		}
		ope.check();
	}
}

void equation::checkanswer(int result) //¼ìÑé´ð°¸ 
{
	Message msg;
	Interface inter;

	cin >> answer;
	char ch = getchar();

	if (answer == result)
	{
		cout << msg.s[1];
		msg.correct += 1;
	}
	else if ((answer != result) && (ch != 'e'))
	{
		cout << msg.s[2] << result;
		msg.wrong += 1;
	}
	if (ch == 'e')
	{
		inter.finally();
	}
}


