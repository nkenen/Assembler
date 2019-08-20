//汇编器的符号表
//目的是为了建立和维持符号与其地址之间的关系
//工具使用c++的map容器，key为string类型，value为int类型

#pragma once
#include <string>
#include <map>

using namespace std;

class SymbolTable
{
public:
	int count;

	SymbolTable();
	~SymbolTable();

	void addEntry(char *c,int addr);//添加符号和地址
	bool contains(char *ads);//查找字符串是否存在
	int GetAddress(char *ads);//返回字符串的地址
private:
	map<string, int> ramcs;
};

