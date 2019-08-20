
#include "Parser.h"

#include <iostream>

#include <windows.h>
#include <commdlg.h>

using namespace std;

string s;

void Openfile() {

	OPENFILENAME ofn;      // 公共对话框结构。   
	TCHAR szFile[256]; // 保存获取文件名称的缓冲区。             
	// 初始化选择文件对话框。   
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
	// 显示打开选择文件对话框。   

	if (GetOpenFileNameA(&ofn))
	{
		//显示选择的文件。   
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