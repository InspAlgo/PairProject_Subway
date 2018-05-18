#include "stdafx.h"
using namespace std;

void Input::InputHandle()
{
	fstream read_file("console_input.txt", ios::in);
	if (!read_file.is_open())
	{
		cout << "Error: Unable to open file correctly." << endl;
		exit(-1);
	}

	getline(read_file, this->order);

	if (this->order == "/a")
	{
		getline(read_file, this->from);
	}
	else if (this->order == "/z")
	{
		getline(read_file, this->from);
	}
	else if (this->order == "/b" || this->order == "/d")
	{
		getline(read_file, this->from);
		getline(read_file, this->to);
	}
	else if (this->order == "/c")
	{
		getline(read_file, this->from);
	}
	else
	{
		read_file.close();
		cout << "Error: Invalid input parameter." << endl
			<< "Please try again!" << endl;
		exit(-1);
	}

	read_file.close();

	if (this->from == this->to)
	{
		cout << "0." << endl;
		exit(0);
	}
}

void Input::SelectModel(Subway &subway)
{
	/* 从某个站开始全遍历并返回 */
	if (this->order == "/a")
	{
		subway.ReadFile();
		subway.GetSingleStation(this->from);
		subway.Traverse();
	}

	/* 求任意两个站点的最短路径 */
	if (this->order == "/b")
	{
		subway.ReadFile();
		subway.GetTwoStation(this->from, this->to);
		subway.Dijkstra();
		subway.PrintPath();
	}

	/* 打印某条地铁线上所有站点 */
	if (this->order == "/c")
	{
		subway.ReadFile();
		subway.PrintBeijingSubwayLine(this->from);
	}

	/* 求任意两个站点的最少换乘路径 */
	if (this->order == "/d")
	{
		subway.ReadFile();
		subway.GetTwoStation(this->from, this->to);
		subway.Transfer();
		subway.Dijkstra();
		subway.PrintPath();
	}

	/* 检查 /a 输出结果的正确性 */
	if (this->order == "/z")
	{
		subway.ReadFile();
		subway.CheckTraverse(this->from);
	}
}