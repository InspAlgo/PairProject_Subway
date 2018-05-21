// DLLCS.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

using namespace std;

void ConsoleInterface()
{
	Input input;
	input.InputHandle();
	Subway subway;
	subway.flag_gui = false;
	input.SelectModel(subway);
}

void GUIInterface()
{
	Input input;
	input.InputHandle();
	Subway subway;
	subway.flag_gui = true;
	input.SelectModel(subway);
}