
// Funcdmentals_GODMODE_MFCDlg.h : header file
//

#pragma once


// CFuncdmentalsGODMODEMFCDlg dialog
class CFuncdmentalsGODMODEMFCDlg : public CDialogEx
{
// Construction
public:
	CFuncdmentalsGODMODEMFCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FUNCDMENTALS_GODMODE_MFC_DIALOG };
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
};
