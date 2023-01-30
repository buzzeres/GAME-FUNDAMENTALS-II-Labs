#include "StateManager.h"

void StateManager::Update()
{
    if (!s_states.empty()) // If the state vector is NOT empty. (Always)
        s_states.back()->Update(); // Invoke the Update of the "current state" 
}

void StateManager::Render()
{
    if (!s_states.empty())
        s_states.back()->Render();
}

void StateManager::PushState(State* pState)
{
}

void StateManager::PopState()
{
}

void StateManager::ChangeState(State* pState)
{
}

void StateManager::Quit()
{
}

std::vector<State*>& StateManager::GetStates()
{
    return s_states;
}

std::vector<State*> StateManager::s_states; // Now this will be allocated.