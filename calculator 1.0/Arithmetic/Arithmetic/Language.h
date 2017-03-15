#pragma once
#include<string>
class Language           //语言资源文件读取
{
public:
	Language();
	void initlanguage();
	void languagelist();
	//void langua();
private:

	char name[10],
		str[100];//内容 
};

