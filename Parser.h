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
	Parser(const char* fileaddress);//传入文件地址
	~Parser();

	void test();//任务程序，所有的处理在这

	void findL();//在真正生成机器码前，符号表对未存在的L符号的增加
	void findA();//符号表对未存在的A符号的增加

	bool hasMoreCommands();//是否还有命令
	void advance();//继续取指令
	int commandType();//返回指令

	char* symbol();//取地址符号，@（）符号可能为数字、符号
	char* dest();//存储目标符号
	char* comp();//运算符号
	char* jump();//跳转符号

	void Savefile();//生成的机器码最后保存在.hack文件中

	void flclose();//将.asm文件关闭
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