#pragma once
using namespace std;

class Input
{
public:
	void InputHandle(int argc, char *argv[]);
	void SelectModel(Subway &subway);
private:
	string from;
	string to;
	string order;
};