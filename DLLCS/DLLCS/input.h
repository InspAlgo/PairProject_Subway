#pragma once
using namespace std;

class Input
{
public:
	void InputHandle();
	void SelectModel(Subway &subway);
	bool flag_gui;
private:
	string from;
	string to;
	string order;
};