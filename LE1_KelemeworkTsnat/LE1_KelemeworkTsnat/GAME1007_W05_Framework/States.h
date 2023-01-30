#pragma once
#ifndef __STATES_H__
#define __STATES_H__

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

#endif