#include "stdafx.h"
using namespace std;

void Input::InputHandle()
{
	fstream read_file("console_input.txt", ios::in);
	fstream output_file("gui_print.txt", ios::out);
	if (!this->flag_gui)
		output_file.close();

	if (!read_file.is_open())
	{
		if (!this->flag_gui)
			cout << "Error: Unable to open file correctly." << endl;
		else
		{
			output_file << "Error" << endl;
			output_file << "Unable to open file correctly in console_input.txt." << endl;
			output_file.close();
		}
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
	else if (this->flag_gui && this->order == "/s")
	{
		getline(read_file, this->from);
	}
	else
	{
		read_file.close();
		if (!this->flag_gui)
		{
			cout << "Error: Invalid input parameter." << endl
				<< "Please try again!" << endl;
		}
		else
		{
			output_file << "Error" << endl;
			output_file << "Invalid input parameter. Please try again!" << endl;
			output_file.close();
		}
		exit(-1);
	}

	read_file.close();

	if (this->from == this->to)
	{
		if (!this->flag_gui)
			cout << "0." << endl;
		else
		{
			output_file << "Error" << endl;
			output_file << "终点不应又同与起点！" << endl;
			output_file.close();
		}
		exit(0);
	}

	if (this->flag_gui)
		output_file.close();
}

void Input::SelectModel(Subway &subway)
{
	/* 从某个站开始全遍历并返回 */
	if (this->order == "/a")
	{
		subway.ReadFile();
		subway.GetSingleStation(this->from);
		if (!subway.flag_exit)
			subway.Traverse();
	}

	/* 求任意两个站点的最短路径 */
	if (this->order == "/b")
	{
		subway.ReadFile();
		subway.GetTwoStation(this->from, this->to);
		if (!subway.flag_exit)
		{
			subway.Dijkstra();
			subway.PrintPath();
		}
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
		if (!subway.flag_exit)
		{
			subway.Transfer();
			subway.Dijkstra();
			subway.PrintPath();
		}
	}

	/* 检查 /a 输出结果的正确性 */
	if (this->order == "/z")
	{
		subway.ReadFile();
		subway.CheckTraverse(this->from);
	}

	/* 以文本输出GUI中站点坐标 */
	if (this->flag_gui && this->order == "/s")
	{
		subway.ReadFile();
		subway.GetSingleStation(this->from);
		if (!subway.flag_exit)
			subway.PrintStationPostion();
	}
}