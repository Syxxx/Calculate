#pragma once
class Message            //  ȫ������
{
public :
	Message();
	void clean();

	static int  s1[20],  //��ʽ��������
		 lan,            //����
		 wrong,
		 correct,
	     bracket_num,
		 bracket_a,
		 bracket_b,
         digit_num;     //��ʽ���ָ���
	static char s2[20]; //��ʽ��������
	static double result;

};



