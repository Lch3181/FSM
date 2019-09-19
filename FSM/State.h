#pragma once
#include<vector>
#include<string>
using namespace std;

class State
{
public:
	State();
	~State();

	State * GetNextState();
	string getTransition();
	string getSelfLoopTransition();
	char GetName();
	bool GetInitialState();
	bool GetFinalState();

	State * addStateAndTransition(char Name, string input);
	State * addTransition(State * name, string input);
	void setSelfLoop(bool input, string acceptInput);

	void setStateName(char Name);
	void setInitialState(bool input);
	void setFinalState(bool input);

private:
	State * nextState;
	string transition;
	bool selfLoop = false;
	string selfLoopTransition;
	bool initialState = false;
	bool FinalState = false;
	char StateName;
};

