//������ķ��ű�
//Ŀ����Ϊ�˽�����ά�ַ��������ַ֮��Ĺ�ϵ
//����ʹ��c++��map������keyΪstring���ͣ�valueΪint����

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

	void addEntry(char *c,int addr);//��ӷ��ź͵�ַ
	bool contains(char *ads);//�����ַ����Ƿ����
	int GetAddress(char *ads);//�����ַ����ĵ�ַ
private:
	map<string, int> ramcs;
};

