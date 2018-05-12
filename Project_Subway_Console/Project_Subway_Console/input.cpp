#include "stdafx.h"
using namespace std;

void Input::InputHandle(int argc, char **argv)
{
	this->order = string(argv[1]);

	if (this->order == "/a")
	{
		cout << "Error: This feature is not supported." << endl;
		exit(-1);
	}
	else if (this->order == "/b" && argc == 4)
	{
		this->from = string(argv[2]);
		this->to = string(argv[3]);
	}
	else
	{
		cout << "Error: Invalid input parameter." << endl
			<< "Please try again!" << endl;
		exit(-1);
	}

	if (this->from == this->to)
	{
		cout << "0." << endl;
		exit(0);
	}
}

void Input::SelectModel(Subway &subway)
{
	if (this->order == "/b")
	{
		subway.ReadFile();
		subway.GetTwoStation(this->from, this->to);
		subway.Dijkstra();
		subway.PrintPath();
	}
}