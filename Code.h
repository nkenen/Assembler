//其实可使用map容器，但是学习map容器前已经写好，感觉没太大改变就不改了

#pragma once
#include <string>

using namespace std;

class Code
{
public:
	Code();
	~Code();

	int dest(char *dst);
	int comp(char *cmp);
	int jump(char *jmp);
private:
	string sdst[8] = {"NULL","M","D","MD","A","AM","AD","AMD"};
	string scmp[28] = {"0","1","-1","D","A","!D","!A","-D","-A","D+1",
		"A+1","D-1","A-1","D+A","D-A","A-D","D&A","D|A","M","!M","-M",
		"M+1","M-1","D+M","D-M","M-D","D&M","D|M"};
	string sjmp[8] = { "NULL","JGT","JEQ","JGE","JLT","JNE","JLE","JMP"};
};

