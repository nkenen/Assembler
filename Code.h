//��ʵ��ʹ��map����������ѧϰmap����ǰ�Ѿ�д�ã��о�û̫��ı�Ͳ�����

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

