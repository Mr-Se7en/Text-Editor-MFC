// copy_window_class.cpp : implementation file
//

#include "pch.h"
#include "File_Editor.h"
#include "afxdialogex.h"
#include "copy_window_class.h"
#include <string>
#include <fstream>
#include "streamopener.h"

// copy_window_class dialog

IMPLEMENT_DYNAMIC(copy_window_class, CDialogEx)

copy_window_class::copy_window_class(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COPY_dlg, pParent)
	, copy_address(_T(""))
	, copy_des_address(_T(""))
{

}

copy_window_class::~copy_window_class()
{
}

void copy_window_class::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Copy_Address, copy_address);
	DDX_Text(pDX, IDC_Copy_Address2, copy_des_address);
}


BEGIN_MESSAGE_MAP(copy_window_class, CDialogEx)
	ON_BN_CLICKED(IDC_Copy_browse, &copy_window_class::OnBnClickedCopybrowse)
	ON_BN_CLICKED(IDCANCEL, &copy_window_class::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_Copy_des_browse, &copy_window_class::OnBnClickedCopydesbrowse)
	ON_BN_CLICKED(IDC_Copy_Save_As, &copy_window_class::OnBnClickedCopySaveAs)
END_MESSAGE_MAP()


// copy_window_class message handlers
CString filePath_copy, filePath_des_copy, read_copy;

void copy_window_class::OnBnClickedCopybrowse()
{
	std::string str = "text (*.txt)|*.txt|";
	LPCSTR pszrFilter = str.c_str();
	CFileDialog dlgFile(TRUE, _T("txt"), _T("document.txt"), OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"), AfxGetMainWnd());
	if (IDOK == dlgFile.DoModal()) {
		filePath_copy = dlgFile.GetPathName();
		copy_address = filePath_copy;
		UpdateData(false);
	}
	std::ifstream my_stream;
	stream_opener(filePath_copy, my_stream);
	char charbuf_copy;
	while (my_stream) {
		charbuf_copy = my_stream.get();
		if (charbuf_copy == 'ÿ')
			break;
		read_copy += charbuf_copy;
	}
	my_stream.close();
}

void copy_window_class::OnBnClickedCopydesbrowse()
{
	std::string str_des = "text (*.txt)|*.txt|";
	LPCSTR pszrFilter = str_des.c_str();
	CFileDialog dlgFile_des(FALSE, _T("txt"), _T("document.txt"), OFN_HIDEREADONLY, _T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"), AfxGetMainWnd());
	if (IDOK == dlgFile_des.DoModal()) {
		filePath_des_copy = dlgFile_des.GetPathName();
		copy_des_address = filePath_des_copy;
		UpdateData(false);
	}
	
}
void copy_window_class::OnBnClickedCopySaveAs()
{
	std::wstring read_copy_alt = CW2T(read_copy);
	std::wofstream my_stream_out;
	stream_opener(filePath_des_copy, my_stream_out);
	my_stream_out << read_copy_alt;
	my_stream_out.close();
	CDialogEx::OnCancel();
}

void copy_window_class::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}






