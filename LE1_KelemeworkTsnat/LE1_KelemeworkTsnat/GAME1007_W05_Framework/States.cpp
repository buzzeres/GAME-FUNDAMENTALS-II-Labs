#include "States.h"
#include "Engine.h"

void State::Render()
{
	SDL_RenderPresent(Engine::Instance().GetRenderer());
}
