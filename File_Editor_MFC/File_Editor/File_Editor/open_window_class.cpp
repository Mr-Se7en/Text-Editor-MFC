// open_window_class.cpp : implementation file
//

#include "pch.h"
#include "File_Editor.h"
#include "afxdialogex.h"
#include "open_window_class.h"
#include <string>
#include <fstream>
#include <windows.h>
#include <shellapi.h>
#include "streamopener.h"

// Extra functions 
//void stream_opener(CString filepath, std::ifstream& my_stream) {
//	try {
//		my_stream.open(filepath, std::ios::binary);
//		if (!my_stream) {
//			throw 10;
//		}
//	}
//	catch (int x) {
//		int msgboxID = MessageBox(NULL,(LPCWSTR)L"failed to open file try again",NULL,NULL);
//	}
//}

// open_window_class dialog

IMPLEMENT_DYNAMIC(open_window_class, CDialogEx)

open_window_class::open_window_class(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OPEN_dlg, pParent)
	, Open_Addresss(_T(""))
	, Open_View(_T(""))
{

}

open_window_class::~open_window_class()
{
}

void open_window_class::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ADDRESSBAR, Open_Addresss);
	DDX_Text(pDX, IDC_OPEN_VIEW, Open_View);
	DDX_Control(pDX, IDC_CHECK3, open_checkbox_control);
}


BEGIN_MESSAGE_MAP(open_window_class, CDialogEx)
	ON_BN_CLICKED(IDC_BROWSE_BUTTON, &open_window_class::OnBnClickedBrowseButton)
	ON_BN_CLICKED(IDC_BUTTON4, &open_window_class::OnBnClickedButton4)
END_MESSAGE_MAP()


// open_window_class message handlers
CString filePath_open, read_alt;
bool filePathed=false;

void open_window_class::OnBnClickedBrowseButton()
{
	std::string str = "text (*.txt)|*.txt|";
	LPCSTR pszrFilter = str.c_str();
	CFileDialog dlgFile(TRUE, _T("txt"), _T("document.txt"), OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"), AfxGetMainWnd());
	if (IDOK == dlgFile.DoModal()) {
		filePath_open = dlgFile.GetPathName();
		Open_Addresss = filePath_open;
		UpdateData(false);
		filePathed = true;
	}
	std::ifstream my_stream;
	stream_opener(filePath_open, my_stream);
	char charbuf;
	CString read;
	while (my_stream) {
		charbuf = my_stream.get();
		if (charbuf == 'ÿ')
			break;
		read += charbuf;
	}
	my_stream.close();
	read_alt = read;
	read_alt.Replace(_T("\n"), _T("\r\n"));

}





void open_window_class::OnBnClickedButton4()//open
{
	if (filePathed) {
		if (open_checkbox_control.GetCheck()) {
			HINSTANCE result = ShellExecute(NULL, L"open", filePath_open, NULL, NULL, SW_SHOWNORMAL);
		}
		else {
			Open_View = read_alt;
			UpdateData(false);
		}
	}
	else
	{
		MessageBox(L"select a directory please");
	}
}





