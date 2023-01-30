#include "States.h"
#include <iostream>
#include "Engine.h"
#include "StateManager.h"

using namespace std;

void State::Render()
{
	SDL_RenderPresent(Engine::Instance().GetRenderer());
}

TitleState::TitleState() {}

void TitleState::Enter()
{
	cout << "Entering TitileState! " << endl;
}

void TitleState::Update()
{
	if (Engine::Instance().KeyDown(SDL_SCANCODE_N))
	{
		cout << " Changing to GameState" << endl;
		STMA::ChangeState(new GameState());
	}
}

void TitleState::Render()
{
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 0, 0, 255, 255);
	SDL_RenderClear(Engine::Instance().GetRenderer());


	State::Render();
}

void TitleState::Exit()
{
	cout << " Exiting TitileState " << endl;
}

GameState::GameState() {}


void GameState::Enter()
{
	cout << " Entering GameState " << endl;
	m_sfx.emplace("track", Mix_LoadWAV("../Assets/aud/mixkit.wav"));
	m_Music.emplace("jump", Mix_LoadWAV("../Assets/aud/mixkit.wav"));
	// Load sfk tracks and add them to map (x2)
	// Load music trrack, and add it to map
	//And play it;

}void GameState::Update()
{
	if (Engine::Instance().KeyDown(SDL_SCANCODE_P))
	{
		cout << " Changing to PauseState " << endl;
		STMA::PushState(new PauseState());
		
	}

}

void GameState::Render()
{
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 0, 255, 0, 255);
	SDL_RenderClear(Engine::Instance().GetRenderer());

	if (dynamic_cast<GameState*>(STMA::GetStates().back()))
		State::Render();
}

void GameState::Exit()
{
	cout << " Exiting TitileState " << endl;
}


void GameState::Resume()
{
	cout << " Resume TitileState " << endl;
}




PauseState::PauseState() {}

void PauseState::Enter()
{
	cout << "Entering PauseState! " << endl;
	m_sfx.emplace("track", Mix_LoadWAV("../Assets/aud/mixkit.wav"));
	m_Music.emplace("jump", Mix_LoadWAV("../Assets/aud/mixkit.wav"));
}


void PauseState::Update()
{
	if (Engine::Instance().KeyDown(SDL_SCANCODE_B))
	{
		cout << " Changing to PauseState " << endl;
		STMA::PushState(new GameState());

	}
}

void PauseState::Render()
{
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 0, 255, 0, 255);
	SDL_RenderClear(Engine::Instance().GetRenderer());

	if (dynamic_cast<PauseState*>(STMA::GetStates().back()))
		State::Render();

}

void PauseState::Exit()
{
	cout << " Exiting TitileState " << endl;
}

void PauseState::Resume()
{
	State::Resume();
}

//EndScene::EndScene()
//{
//}
//
//EndScene::~EndScene()
//{
//}
//
//void EndScene::Draw()
//{
//}
//
//void EndScene::Update()
//{
//}
//
//void EndScene::Clean()
//{
//}
//
//void EndScene::HandleEvents()
//{
//}
//
//void EndScene::Start()
//{
//}

