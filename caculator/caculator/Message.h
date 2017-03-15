#pragma once
class Message            //  全局数据
{
public :
	Message();
	void clean();

	static int  s1[20],  //算式数字数组
		 lan,            //语言
		 wrong,
		 correct,
	     bracket_num,
		 bracket_a,
		 bracket_b,
         digit_num;     //算式数字个数
	static char s2[20]; //算式符号数组
	static double result;

};



