// #pragma once
#ifndef __ENGINE_H__
#define __ENGINE_H__
#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <SDL_mixer.h>
#include <chrono>
#include <string>
using namespace std;

#define WIDTH 1024
#define HEIGHT 768
#define FPS 60

class Engine
{
public: // Put public heading first so you ALWAYS question why things are public!
	
	int Run();
	bool KeyDown(SDL_Scancode);
	SDL_Renderer* GetRenderer();
	static Engine& Instance(); // Accessor for Engine object.
	double deltaTime{};

private:
	Engine();
	// For fixed timestep.
	chrono::time_point<chrono::steady_clock> m_start, m_end;
	chrono::duration<double> m_diff{};
	double m_fps{}; // Changed to double.

	const Uint8* m_pKeystates{};
	SDL_Window* m_pWindow; // Pointers are normal variables that hold addresses.
	SDL_Renderer* m_pRenderer; // Pointer to "back buffer"
	bool m_isRunning;

	map<string, Mix_Chunk*> m_sfx;
	map<string, Mix_Chunk*> m_Music;

	// Example-specific properties.


	chrono::time_point<chrono::steady_clock> lastFrameTime, thisFrameTime; // Cleaned this up.
	chrono::duration<double> lastFrameDuration{};
	int Init(const char*, const int, const int, const int, const int, const int);
	//void Mix_PlayChannel(int channel, map<string, _Mix_Music*>::mapped_type chunk, int loops);
	//void Mix_PlayChannel(int channel, map<string, Mix_Chunk*>::mapped_type chunk, int loops);
	//map<string, Mix_Chunk*> operator&(const map<string, Mix_Chunk*>& map, const map<string, Mix_Chunk*>& rhs);

	void HandleEvents();
	void Wake();
	void Update();
	void Sleep();
	void Render();
	void Clean();	
};

#endif
