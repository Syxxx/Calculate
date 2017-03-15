#include "stdafx.h"
#include "Message.h"

int Message::s1[20] = { 0 },
Message::wrong = 0,
Message::correct = 0,
Message::bracket_num = 0,
Message::bracket_a = 0,
Message::bracket_b = 0,
Message::digit_num = 0,
Message::equation_num = 0;

char   Message::s2[20] = { 0 },
Message::s[10][200] = { 0 };
double Message::result = 0.0;

Message::Message()
{}

void Message::clean() {
	s1[10] = { 0 };
	s2[10] = { 0 };
	bracket_num = 0;
	bracket_a = 0;
	bracket_b = 0;
	result = 0.0;
	digit_num = 0;
}