#define _CRT_SECURE_NO_WARNINGS

#include "Parser.h"

#include <bitset>
#include <string>


Parser::Parser(const char* fileaddress){
	fname = fileaddress;
	fln.open(fname);
	if(!fln.is_open()){
		cout << "open file error" << endl;
	}
	count = 0;
	fln.seekg(0, ios::beg);	
}

Parser::~Parser(){
	

}


void Parser::test() {

	char *Asyb = NULL, *cmp = NULL, *dst = NULL, *jmp = NULL, *Lsyb = NULL;//����ָ���ַ��Ļ�����
	int add = 0, cmd ;//addΪ��ַ������ֵ��cmdΪcָ�������ֵ
	bitset<16> t;//16λ�����ƻ����뻺����
	
	//���������ɻ�����ǰ�����ű��δ���ڵ�L��A���ŵ�����
	findL();
	findA();

	while (hasMoreCommands())//���ɻ������ѭ��
	{
		int i = 0;
		advance();//ȡָ��
		int c1 = commandType();//�õ�ָ������
		switch (c1) {
		case A_COMMAND://A��ָ���
			add = 0;
			cout << "-----A-----" << endl;
			Asyb = symbol();
			if (st.contains(Asyb)) {
				add = st.GetAddress(Asyb);//ȡ���ŵĵ�ֵַ
			}
			else {//�����ڵľ�Ϊ����ֵ�������㷨�����ַ���int��ת��
				while (Asyb[i] != '\0') i++;
				--i;
				int j = 0;
				while (i >= 0)
				{		
					add = add + (Asyb[i] - '0') * pow(10, j++);
					i--;
				}
			}
			t = bitset<16>(add);
			bstr +=t.to_string() + "\n";//bstrΪ������Ļ�����
			break;
		case C_COMMAND://C��ָ���
			cmd = 7 << 13;
			cout << "-----C-----" << endl;
			cmp = comp();
			dst = dest();
			jmp = jump();
			cmd = cmd | (c.comp(cmp) << 6) | (c.dest(dst) << 3) | c.jump(jmp);//���ݻ�����c���ʽ

			t = bitset<16>(cmd);
			bstr += t.to_string() + "\n";
			break;
		case L_COMMAND:
			cout << "-----L-----" << endl;
			break;
		default:

			break;
		}
	}
	Savefile();//����������ļ�

	flclose();
}

void Parser::Savefile() {
	string name;
	//��������ͬ�ļ���
	int Index = fname.find(".asm");
	name = fname.substr(0, Index);
	name += ".hack";
	const char *na = name.c_str();

	//�����ļ�
	FILE *fpc = fopen(na,"w");
	fclose(fpc);

	//д�ļ�
	fstream fp1(name);
	fp1 << bstr;
	fp1.close();
}

void Parser::findA() {
	char *Asyb = NULL;
	while (hasMoreCommands())
	{
		advance();
		int c = commandType();
		if (c == A_COMMAND) {
			Asyb = symbol();
			if (!(Asyb[0] >= '0'&&Asyb[0] <= '9')) {//��Ϊ�����ַ���
				if (!st.contains(Asyb)) {//�����ڷ��ű���
					st.addEntry(Asyb, st.count);
					st.count++;
				}
			}
		}
	}
	fln.clear();//����Ҫһ��Ҫ����clear������������Ȼ�޷����¶�λ���ļ���ͷ
	fln.seekg(0, ios::beg);
}

void Parser::findL() {
	char  *Lsyb = NULL;
	while (hasMoreCommands())
	{
		advance();
		int c = commandType();
		if (c == L_COMMAND) {
			Lsyb = symbol();
			st.addEntry(Lsyb, pc);
		}
		else if (c != -2 && c != -1)
		{
			pc++;//����Ҫ��pc��ָ���¸����е�ָ��ڷ��ű���Lָ���ֵΪpcֵ������RAM��ֵַ�����ֵַ�����ظ�
		}
	}
	fln.clear();
	fln.seekg(0, ios::beg);
}

bool Parser::hasMoreCommands(){
	if (!fln.eof()) {
		delete[] syb;
		delete[] dst;
		delete[] cmp;
		delete[] jmp;
		return true;
	}
	else return false;
}

void Parser::advance(){	
	fln.getline(buf, sizeof(buf));
	syb = new char[strlen(buf)];
	dst = new char[strlen(buf)];
	cmp = new char[strlen(buf)];
	jmp = new char[strlen(buf)];
}

int Parser::commandType(){
	int i = 0;
	while (buf[i] != '\0' ){
		if (buf[i] != ' ') {
			if (buf[i] == '@')
				return A_COMMAND;
			else if (buf[i] == '(')
				return L_COMMAND;
			else if (buf[i] != '/')
				return C_COMMAND;
			else if (buf[i] == '/')
				return -2;
		}
		i++;
	}
	return -1;	
}

char* Parser::symbol(){
	int i = 0,j = 0;

	while (  buf[i] != '\0' &&  buf[i] != '/'){
		if (buf[i] != ' '  && buf[i] != '(' && buf[i] != '@' && buf[i] != ')') {
			syb[j] = buf[i];
			j++;
		}
		i++;		
	}
	syb[j] = '\0';
	return syb;
	
}

char* Parser::dest(){
	int i = 0,j = 0;
	
	while (buf[i] != '\0' &&  buf[i] != '/')
	{
		if (buf[i] == '=') {
			break;
		}
		else if(buf[i] != ' ' ){
			dst[j]= buf[i];
			j++;
		}
		i++;
	}
	if(buf[i] == '=')
		dst[j] = '\0';
	else dst[0] = '\0';
	return dst;
}

char* Parser::comp() {

	int i = 0, j = 0;
	
	while (buf[i] != '=' && buf[i] != ';' && buf[i] != '\0' &&  buf[i] != '/'){
		i++; 
	}

	if (buf[i] == '=') {
		i++;
		while (buf[i] != '\0' &&  buf[i] != '/') {
			if (buf[i] != ' '){
				cmp[j] = buf[i];
				j++;
			}
			i++;	
		}
	}
	else{	
		if (buf[i] != '\0') {
			i--;
			while (i>=0 && buf[i] != ' '){
				if (buf[i] != ' ') {
					cmp[j] = buf[i];
					j++;
				}
				i--;	
			}
		}
	}
	cmp[j] = '\0';
	return cmp;
}

char* Parser::jump(){

	int i = 0,j = 0;
	

	while (buf[i] != ';' && buf[i] != '\0' &&  buf[i] != '/') { i++; }

	if (buf[i] == ';') {
		i++;
		while (buf[i] != '\0' &&  buf[i] != '/') {
			if (buf[i] != ' ') {
				jmp[j] = buf[i];
				j++;
			}
			i++;
			
		}
	}
	jmp[j] = '\0';
	return jmp;
}

void Parser::flclose() {
	fln.close();

}
