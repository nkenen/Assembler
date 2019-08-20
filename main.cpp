
#include "Parser.h"

#include <iostream>

#include <windows.h>
#include <commdlg.h>

using namespace std;

string s;

void Openfile() {

	OPENFILENAME ofn;      // �����Ի���ṹ��   
	TCHAR szFile[256]; // �����ȡ�ļ����ƵĻ�������             
	// ��ʼ��ѡ���ļ��Ի���   
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = "All(*.*)\0*.*\0Text(*.txt)\0*.TXT\0\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	//ofn.lpTemplateName =  MAKEINTRESOURCE(ID_TEMP_DIALOG);  
	// ��ʾ��ѡ���ļ��Ի���   

	if (GetOpenFileNameA(&ofn))
	{
		//��ʾѡ����ļ���   
		s = szFile;
	}
}

int main()
{    
	Openfile();

	Parser *p = new Parser(s.c_str());
	p->test();

	delete p;
	system("pause");
	return 0;
}

/*int main(){
	int i = 0;

	OPENFILENAME ofn = {0};

	GetOpenFileNameA(&ofn);

	cout << ofn.lpstrFile << endl;
	
	
	system("pause");
	return 0;
}*/