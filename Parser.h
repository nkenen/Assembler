#ifndef _PARSER_H_ 
#define _PARSER_H_

#include <string>
#include <fstream>
#include <iostream>

#include "Code.h"
#include "SymbolTable.h"

using namespace std;

#define A_COMMAND  1
#define C_COMMAND  2
#define L_COMMAND  3

class Parser
{
public:
	Parser(const char* fileaddress);//�����ļ���ַ
	~Parser();

	void test();//����������еĴ�������

	void findL();//���������ɻ�����ǰ�����ű��δ���ڵ�L���ŵ�����
	void findA();//���ű��δ���ڵ�A���ŵ�����

	bool hasMoreCommands();//�Ƿ�������
	void advance();//����ȡָ��
	int commandType();//����ָ��

	char* symbol();//ȡ��ַ���ţ�@�������ſ���Ϊ���֡�����
	char* dest();//�洢Ŀ�����
	char* comp();//�������
	char* jump();//��ת����

	void Savefile();//���ɵĻ�������󱣴���.hack�ļ���

	void flclose();//��.asm�ļ��ر�
protected:

private:
	fstream fln;
	string fname;
	string bstr;
	int count;
	char buf[256];
	char *syb;
	char *dst;
	char *cmp;
	char *jmp;

	Code c;
	SymbolTable st;
	
	int pc = 0;
};

#endif