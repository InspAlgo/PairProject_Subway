// DLLCS.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

using namespace std;

void Interface()
{
	Input input;
	input.InputHandle();
	Subway subway;
	input.SelectModel(subway);
}