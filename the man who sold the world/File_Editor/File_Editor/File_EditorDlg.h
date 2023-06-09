
// File_EditorDlg.h : header file
//

#pragma once


// CFileEditorDlg dialog
class CFileEditorDlg : public CDialogEx
{
// Construction
public:
	CFileEditorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILE_EDITOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedass();
	afx_msg void OnBnClickedencryption();
	afx_msg void OnBnClickedOpen();
	afx_msg void OnBnClickedCopy();
	afx_msg void OnBnClickedExit();
};
