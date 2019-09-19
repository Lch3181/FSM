#include "FSM.h"



FSM::FSM()
{
}


FSM::~FSM()
{
}

void FSM::addState(string StateName)
{
	this->fsm.push_back(StateName);
}
