#pragma once
#include<vector>
#include<string>
using namespace std;
class FSM
{
public:
	FSM();
	~FSM();

	void addState(string StateName);
	void acceptInput();
	void addTransition();
private:
	vector<FSM> fsm;
};

