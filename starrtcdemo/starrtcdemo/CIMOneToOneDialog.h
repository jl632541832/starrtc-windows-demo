#pragma once
#include "CSqliteDB.h"
#include "XHChatManager.h"
#include <list>
// CIMOneToOneDialog 对话框

class CIMOneToOneDialog : public CDialogEx, public IChatManagerListener
{
	DECLARE_DYNAMIC(CIMOneToOneDialog)

public:
	CIMOneToOneDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CIMOneToOneDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ONE_TO_ONE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual void onReceiveMessage(CIMMessage* var1);
public:
	
	afx_msg void OnBnClickedButtonCreateNewOneToOne();
	afx_msg void OnBnClickedButtonSendMessage();
	CListCtrl m_OneToOneList;
	CImageList m_imList;
	CSqliteDB* m_pSqliteDB;
	XHChatManager* m_pChatManager;
	
	CEdit m_sendMsgEdit;
	string m_strDisUserId;
	CListBox m_contentCombox;
	string m_strUserId;
	list<CMessageBean*> mDatas;
	list<CHistoryBean*> mHistoryDatas;
	void clearMsgList();
	void getMsgList(string conversationId);
	void clearHistoryList();
	void getHistoryList();
	void addHistoryList(CHistoryBean* pHistoryBean);
	void resetMsgList();
	void resetHistoryList();
	virtual BOOL OnInitDialog();
	CStatic m_AimId;
	afx_msg void OnNMClickListOneToOneList(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
