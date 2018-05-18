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
	/* ��ĳ��վ��ʼȫ���������� */
	if (this->order == "/a")
	{
		subway.ReadFile();
		subway.GetSingleStation(this->from);
		subway.Traverse();
	}

	/* ����������վ������·�� */
	if (this->order == "/b")
	{
		subway.ReadFile();
		subway.GetTwoStation(this->from, this->to);
		subway.Dijkstra();
		subway.PrintPath();
	}

	/* ��ӡĳ��������������վ�� */
	if (this->order == "/c")
	{
		subway.ReadFile();
		subway.PrintBeijingSubwayLine(this->from);
	}

	/* ����������վ������ٻ���·�� */
	if (this->order == "/d")
	{
		subway.ReadFile();
		subway.GetTwoStation(this->from, this->to);
		subway.Transfer();
		subway.Dijkstra();
		subway.PrintPath();
	}

	/* ��� /a ����������ȷ�� */
	if (this->order == "/z")
	{
		subway.ReadFile();
		subway.CheckTraverse(this->from);
	}
}