#pragma once
class equation                //算式及结果显示
{
public:
	equation();
	void initequation();
	void bracket();           //添加括号
	void checkanswer(int result);
	void finally();           //统计结果 
private:
	int answer,   //输入的答案
		 m[20];    //算式数字  
	char n[20];   //算式符号

};

