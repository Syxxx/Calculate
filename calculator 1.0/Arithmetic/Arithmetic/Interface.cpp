#include "stdafx.h"
#include "Interface.h"
#include "Message.h"
#include "Language.h"
#include<iostream>
using namespace std;

Interface::Interface()
{
}

void Interface::first()
{
	Message msg;
	Language lang;
	cout << "***********************************************" << endl;
	cout << "Please choose the language:" << endl;

	lang.languagelist();
	lang.initlanguage();
	cout << msg.s[0];
	cin >> msg.equation_num;
	cout << "***********************************************" << endl;
}
void Interface::finally()
{
	Message msg;
	cout << endl;
	cout << "***********************************************" << endl;
	cout << msg.s[3] << msg.correct << msg.s[5] << msg.s[4] << msg.wrong << msg.s[5] << endl;
	cout << "***********************************************" << endl;
}