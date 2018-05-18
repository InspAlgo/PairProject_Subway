#pragma once
using namespace std;

class Input
{
public:
	void InputHandle();
	void SelectModel(Subway &subway);
private:
	string from;
	string to;
	string order;
};