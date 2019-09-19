#include<iostream>
#include"State.h"
using namespace std;
void evenBinaryNumbersFSM();
void EmailFSM();

int main()
{
	evenBinaryNumbersFSM();

	EmailFSM();

	getchar();
	getchar();
	return 0;
}

void evenBinaryNumbersFSM()
{
	//var
	State * current;
	string input;

	//create a fsm for example 1, fsm that only takes even binary numbers
	State * init = new State();
	init->setStateName('A');
	init->setSelfLoop(true, "1");
	State * B = init->addStateAndTransition('B', "0");
	B->setFinalState(true);
	B->setSelfLoop(true, "0");
	B->addTransition(init, "1");

	//fsm starts at init state
	current = init;

	//get user input
	cout << "Please enter a even binary numbers: ";
	cin >> input;

	//loop through each input letters
	for (int i = 0; i < input.size(); i++)
	{
		size_t found, found2;
		found = current->getTransition().find(input[i]);
		found2 = current->getSelfLoopTransition().find(input[i]);

		if (found != string::npos)//if possible to next state
		{
			current = current->GetNextState();
		}
		else if (found2 != string::npos)// if possible to self state
		{
			continue;
		}
		else// input invalid
		{
			cout << "character: " << input[i] << " invalid" << endl;
			break;
		}


	}

	//check if end up at final state
	if (current->GetFinalState())
	{
		cout << "Input accepted" << endl;
	}
	else
	{
		cout << "Input rejected" << endl;
	}

	//delete pointers
	delete init, B;
}

void EmailFSM()
{
	//var
	State * current;
	string input;
	bool multiPaths = false;
	string LowerCaseLetters_period_underscore("._qwertyuiopasdfghjklzxcvbnm");
	string LowerCaseLetters_underscore("_qwertyuiopasdfghjklzxcvbnm");
	string LowerCaseLetters("qwertyuiopasdfghjklzxcvbnm");

	//create a fsm for example 2, fsm that takes email 
	State * init = new State();
	init->setStateName('A');
	State * B = init->addStateAndTransition('B', LowerCaseLetters_period_underscore);
	B->setSelfLoop(true, LowerCaseLetters_period_underscore);
	State * C = B->addStateAndTransition('C', "@");
	C->setSelfLoop(true, LowerCaseLetters_underscore);
	State * D = C->addStateAndTransition('D', ".");
	State * E = D->addStateAndTransition('E', LowerCaseLetters);
	E->setSelfLoop(true, LowerCaseLetters);
	E->setFinalState(true);

	//fsm starts at init state
	current = init;

	//get user input
	cout << "Please enter an e-mail address: ";
	cin >> input;

	//loop through each input letter
	for (int i = 0; i < input.size(); i++)
	{
		size_t found, found2;
		found = current->getTransition().find(input[i]);
		found2 = current->getSelfLoopTransition().find(input[i]);
		
		if (found2 != string::npos)//in possible to self state
		{
			
		}
		else if(found!=string::npos)// if possible to next state
		{
			current = current->GetNextState();
		}
		else// input invalid
		{
			cout << "character: " << input[i] << " invalid" << endl;
			cout << "only lower-case letters, period, and underscore allowed." << endl;
			break;
		}

	}

	//check if ends at final state
	if (current->GetFinalState())
	{
		cout << "Input accepted" << endl;
	}
	else
	{
		cout << "Input rejected" << endl;
	}

	//delete pointers
	delete init, B, C, D, E;
}