#pragma once
#include "afxdialogex.h"


// Encryption_window_class dialog

class Encryption_window_class : public CDialogEx
{
	DECLARE_DYNAMIC(Encryption_window_class)

public:
	Encryption_window_class(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Encryption_window_class();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ENCRYPTION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	void ShowToggle(bool show);
	void ShowToggle2(bool show);
public:
	afx_msg void OnBnClickedEncryptionSave();
	int encrypt_decrypt_Choice;
	CStatic des_address_boc_CTRL;
	CStatic enc_des_browse_CTRL;
	CStatic enc_save_CTRL;
	CStatic save_as_grouper_CTRL;
	afx_msg void OnBnClickedEncryptionview();
	afx_msg void OnBnClickedEncryptionsavechoice();
	int save_view_choice_int;
	CButton enc_view_button_CTRL;
	afx_msg void OnBnClickedEncryptionbrowse();
	CString enc_address;
	int key;
	CString enc_des_address;
	afx_msg void OnBnClickedEncryptiondesbrowse();
	CString enc_result_view;
	afx_msg void OnBnClickedEncryptionViewButton();
	int key_in;
	afx_msg void OnBnClickedencsubmitDecrypt();
	afx_msg void OnBnClickedencsubmitEncrypt();
	afx_msg void OnBnClickedEncryptchoice();
	afx_msg void OnBnClickedDecryptchoice();
	CStatic enc_key_in_CTRL;
	CStatic enc_submit_decrypt_CTRL;
	CStatic decryption_group_text;
	CStatic enc_key_CTRL;
	CStatic enc_submit_encrypt;
	CStatic encryption_group_text;
};
