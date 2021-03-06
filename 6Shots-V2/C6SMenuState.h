#ifndef __C6SMENUSTATE_H__
#define __C6SMENUSTATE_H__

#include "CGameState.h"

/* Main Menu */
class C6SMenuState : public CGameState {
	static C6SMenuState m_MenuState;
	tgui::Gui* m_pGui;

	const int MENU_TEXT_SIZE = 24;
	const tgui::Layout2d MENU_BUTTON_SIZE = tgui::Layout2d(200, 30);
	const tgui::Layout MENU_BUTTON_SPACE = 10;
	const tgui::Layout MENU_BUTTON_OFFSET_X = -1 * (MENU_BUTTON_SIZE.x / 2);

public:
	void C6SMenuState::Init(CGame* pGame);
	void C6SMenuState::Cleanup(CGame* pGame);

	void C6SMenuState::Draw(CGame* pGame);
	void C6SMenuState::Update(CGame* pGame, float fFrameTime);
	void C6SMenuState::HandleInput(CGame* pGame);

	void C6SMenuState::PauseState();
	void C6SMenuState::ResumeState();

	static C6SMenuState* Instance()
	{
		return &m_MenuState;
	}
};

#endif

