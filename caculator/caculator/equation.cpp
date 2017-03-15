#include "stdafx.h"
#include "equation.h"
#include "operate.h"
#include "Message.h"
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

	for (int i = 0;i < msg.digit_num ;i++)
	{
		m[i] = rand() % 8 + 1;    
		n[i] = c[rand() % 4]; 
	}
	n[msg.digit_num - 1] = '=';
	bracket();
}

void equation::bracket() { 
	operate ope;
	Message msg;

	msg.bracket_num = rand() % 2; 


	if (msg.bracket_num == 1)
	{
		msg.bracket_a = rand() % ((msg.digit_num - 1) / 2) + 1;
		msg.bracket_b = msg.bracket_a + rand() % ((msg.digit_num - 1) / 2) + 2;
									
		for (int i = 0; i < msg.digit_num; i++ )
		{
			msg.s1[i] = m[i];  //���� 
			msg.s2[i] = n[i];  //���� 
		}
		ope.check();
	}
	else if (msg.bracket_num == 0)
	{
		for (int i = 0; i < msg.digit_num; i++)
		{
			msg.s1[i] = m[i];  //���� 
			msg.s2[i] = n[i];  //���� 
		}
		ope.check();
	}
}

void equation::checkanswer(int result) //����� 
{
	Message msg;
	cin >> answer;
	char ch = getchar();

	if (answer == result)
	{
		if (msg.lan == 1)
			cout << "     ����ȷ";
		else
			cout << "     correct";
		msg.correct += 1;
	}
	else if ((answer != result) && (ch != 'e'))
	{
		if (msg.lan == 1)
			cout << "     �𰸴�����ȷ��Ϊ:" << result;
		else
			cout << "     wrong answer. The correct answer is:" << result;
		msg.wrong += 1;
	}
	if (ch == 'e')
	{
		finally();
	}
}

void equation::finally() //ͳ�ƽ�� 
{
	Message msg;
	if (msg.lan == 1)
		cout << endl << "����" << msg.correct << "����;" << "����" << msg.wrong << "����" << endl;
	else
		cout << endl << "Correct questions:" << msg.correct << ";Wrong questions:" << msg.wrong<< endl;
	exit(0);
}

