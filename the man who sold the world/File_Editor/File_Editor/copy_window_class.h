#pragma once
#include "afxdialogex.h"


// copy_window_class dialog

class copy_window_class : public CDialogEx
{
	DECLARE_DYNAMIC(copy_window_class)

public:
	copy_window_class(CWnd* pParent = nullptr);   // standard constructor
	virtual ~copy_window_class();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COPY_dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCopybrowse();
	CString copy_address;
	afx_msg void OnBnClickedCancel();
	CString copy_des_address;
	afx_msg void OnBnClickedCopydesbrowse();
	afx_msg void OnBnClickedCopySaveAs();
};
