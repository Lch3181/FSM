#include "State.h"



State::State()
{
}


State::~State()
{
	
}

State * State::GetNextState()
{
	return nextState;
}

string State::getTransition()
{
	return transition;
}

string State::getSelfLoopTransition()
{
	return selfLoopTransition;
}

char State::GetName()
{
	return StateName;
}

bool State::GetInitialState()
{
	return initialState;
}

bool State::GetFinalState()
{
	return FinalState;
}

State * State::addStateAndTransition(char Name, string input)
{
	nextState = new State();
	nextState->setStateName(Name);
	transition = input;
	return nextState;
}

State * State::addTransition(State * name, string input)
{
	transition = input;
	nextState = name;
	return name;
}

void State::setSelfLoop(bool input, string acceptInput)
{
	selfLoop = input;
	selfLoopTransition = acceptInput;
}

void State::setStateName(char Name)
{
	StateName = Name;
}

void State::setInitialState(bool input)
{
	initialState = input;
}

void State::setFinalState(bool input)
{
	FinalState = input;
}
