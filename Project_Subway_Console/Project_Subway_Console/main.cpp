// Project_Subway_Console.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;

int main(int argc, char *argv[])
{
	Input input;
	input.InputHandle(argc, argv);
	Subway subway;
	input.SelectModel(subway);
    return 0;
}

