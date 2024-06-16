#pragma once
#include "afxdialogex.h"


// open_window_class dialog

class open_window_class : public CDialogEx
{
	DECLARE_DYNAMIC(open_window_class)

public:
	open_window_class(CWnd* pParent = nullptr);   // standard constructor
	virtual ~open_window_class();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPEN_dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString Open_Addresss;
	afx_msg void OnBnClickedBrowseButton();
	afx_msg void OnBnClickedButton4();
	CString Open_View;
	CButton open_checkbox_control;
};
