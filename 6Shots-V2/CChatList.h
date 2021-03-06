#ifndef __CCHATLIST_H__
#define __CCHATLIST_H__

#define CHATLIST_BEGIN_FADE_TIME 9.0f
#define CHATLIST_END_FADE_TIME 10.0f
class CGame;
class CChatList
{
	static const int iChatlistBufferSize = 5;
	static const int iChatlistDefaultFontSize = 24;
	int m_iFontSize;
	int m_iNumMessages;
	char* m_pszMessageBuffer[iChatlistBufferSize];
	float m_fTimeSinceLastShown;

public:
	CChatList() {
		m_iFontSize = iChatlistDefaultFontSize;
		m_iNumMessages = 0; 
		m_fTimeSinceLastShown = 0.0f;
	}
	~CChatList();

	void Draw(CGame* pGame);
	void AddMessage(char* szMessage);
	void Update(float fFrameTime);
	void Show();
};

#endif