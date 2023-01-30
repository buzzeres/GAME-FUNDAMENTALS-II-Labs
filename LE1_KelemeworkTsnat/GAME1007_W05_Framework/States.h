#ifndef __STATES_H__
#define __STATES_H__
#include <map>
#include <SDL_mixer.h>
#include <string>

class State // Abstract base class.
{ // No objects of State can be created.
public:
	virtual void Enter() = 0; // Pure virtual function. No definition.
	virtual void Update() = 0;
	virtual void Render(); // Will be defined in State.
	virtual void Exit() = 0;
	virtual void Resume() {}; // Considered defined for all subclasses.
protected: // Private but inherited.
	State() = default;
};


class TitleState :public State
{
public:
	TitleState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();
private:
};

class GameState : public State
{
public:
	GameState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();
	virtual void Resume();

private:
	// add map for music tracks that goes here
	// // add map for music tracks that goes here
	std::map<std::string, Mix_Chunk*> m_sfx;
	std::map<std::string, Mix_Chunk*> m_Music;
};

class PauseState : public State
{
public:
	PauseState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();
	virtual void Resume();
private:
	std::map<std::string, Mix_Chunk*> m_sfx;
	std::map<std::string, Mix_Chunk*> m_Music;
};

//class EndScene final : public State
//{
//public:
//	EndScene();
//	~EndScene();
//
//	// Inherited via Scene
//	virtual void Draw();
//	virtual void Update();
//	virtual void Clean();
//	virtual void HandleEvents();
//	virtual void Start();
//private:
//};
#endif