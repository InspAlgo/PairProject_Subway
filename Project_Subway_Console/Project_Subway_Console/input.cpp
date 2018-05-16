#include "stdafx.h"
using namespace std;

void Input::InputHandle(int argc, char **argv)
{
	this->order = string(argv[1]);

	if (this->order == "/a" && argc == 3)
	{
		this->from = string(argv[2]);
	}
	else if ((this->order == "/b" || this->order == "/d") && argc == 4)
	{
		this->from = string(argv[2]);
		this->to = string(argv[3]);
	}
	else if (this->order == "/c" && argc == 3)
	{
		this->from = string(argv[2]);
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

}