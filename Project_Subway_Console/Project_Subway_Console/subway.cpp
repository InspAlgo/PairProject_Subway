#include "stdafx.h"
using namespace std;

Subway::Subway()
{
	this->station_name = new string[STATION_NUM];
	this->station_link = new Link*[STATION_NUM];
	this->station_path = new int*[STATION_NUM];
	for (int i = 0; i < STATION_NUM; i++) //除自身外一开始每个点都不可达
	{
		station_name[i] = "";
		this->station_link[i] = new Link[STATION_NUM];
		this->station_path[i] = new int[STATION_NUM];
		for (int j = 0; j < STATION_NUM; j++)
		{
			station_path[i][j] = -1; //初值为-1，即没有路径
			if (i == j)
				station_link[i][j].value = 0;
			else
				station_link[i][j].value = INF;
		}
	}
}

void Subway::ReadFile()
{
	fstream read_file("beijing-subway.txt", ios::in);

	if (!read_file.is_open())
	{
		cout << "Error: Unable to open file correctly." << endl;
		exit(-1);
	}

	int pos_0, pos_1, pos_2, pos_3;
	string str_line, temp_str;

	while (getline(read_file, str_line))
	{
		if (str_line[0] == '&')
		{
			stringstream ss_1, ss_2, ss_3;
			int pos_x, pos_y, pos_station;
			int i = 1;
			pos_0 = i;
			while (str_line[++i] != ' ');
			pos_1 = i;
			while (str_line[++i] != ' ');
			pos_2 = i;
			while (str_line[++i] != ' ');
			pos_3 = i;
			ss_1 << str_line.substr(pos_3 + 1);
			ss_1 >> pos_y;
			ss_2 << str_line.substr(pos_2 + 1, pos_3 - pos_2 - 1);
			ss_2 >> pos_x;
			temp_str = str_line.substr(pos_1 + 1, pos_2 - pos_1 - 1);
			ss_3 << str_line.substr(pos_0 + 1, pos_1 - pos_0 - 1);
			ss_3 >> pos_station;
			this->station_name[pos_station] = temp_str;
			this->name_to_num[temp_str] = pos_station;
		}
		if (str_line[0] == '#')
		{
			stringstream ss_1, ss_2, ss_3, ss_4;
			int temp_1, temp_2, temp_3;
			int i = 1;
			pos_0 = i;
			while (str_line[++i] != ' ');
			pos_1 = i;
			while (str_line[++i] != ' ');
			pos_2 = i;
			while (str_line[++i] != ' ');
			pos_3 = i;
			ss_4 << str_line.substr(pos_3);
			ss_3 << str_line.substr(pos_2 + 1, pos_3 - pos_2 - 1);
			ss_3 >> temp_3;
			ss_2 << str_line.substr(pos_1 + 1, pos_2 - pos_1 - 1);
			ss_2 >> temp_2;
			ss_1 << str_line.substr(pos_0 + 1, pos_1 - pos_0 - 1);
			ss_1 >> temp_1;
			this->station_link[temp_1][temp_2].value = temp_3;
			ss_4 >> this->station_link[temp_1][temp_2].line_name;
		}
	}

	read_file.close();
}

void Subway::GetTwoStation(string start_station, string end_station)
{
	this->start_station_ = this->name_to_num[start_station];
	this->end_station_ = this->name_to_num[end_station];
}

void Subway::Dijkstra()
{
	int book[STATION_NUM];  // book[]节点是否被访问
	int dis[STATION_NUM];  // dis[i]起始点到i的最短距离

	memset(book, 0, sizeof(book));  // 一开始每个点都没被访问
	for (int i = 0; i < STATION_NUM; i++)
	{
		dis[i] = this->station_link[this->start_station_][i].value;
		if (dis[i] < INF)  // start_station到i有直接路径
		{
			this->station_path[i][0] = this->start_station_;
			this->station_path[i][1] = i;
		}
	}

	/* 核心语句 */
	for (int i = 0; i < STATION_NUM - 1; i++)
	{
		int min = INF;
		int u;
		for (int j = 0; j < STATION_NUM; j++)
		{
			if (book[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (int v = 0; v < STATION_NUM; v++)
		{
			if (!book[v] && dis[v] > dis[u] + this->station_link[u][v].value)
			{
				dis[v] = dis[u] + this->station_link[u][v].value;
				for (int i = 0; i < STATION_NUM; i++)
				{
					this->station_path[v][i] = this->station_path[u][i];
					if (this->station_path[v][i] == -1)
					{
						this->station_path[v][i] = v;
						this->station_path_num_ = i + 1;
						break;
					}
				}
			}
		}
	}
}

void Subway::PrintPath()
{
	int flag_output = 0;
	cout << this->station_path_num_ << endl;

	for (int i = 0; i < STATION_NUM; i++)
	{
		if (this->station_path[this->end_station_][i] > -1)
		{
			cout << this->station_name[this->station_path[end_station_][i]];
			if (i != 0 && this->station_path[this->end_station_][i - 1] > -1 
				&& this->station_path[this->end_station_][i + 1] > -1)
			{
				if (this->station_link[this->station_path
					[this->end_station_][i - 1]]
					[this->station_path[this->end_station_][i]].line_name
					!= this->station_link[this->station_path
					[this->end_station_][i]]
					[this->station_path[this->end_station_][i + 1]].line_name)
				{
					cout << " 换乘" << this->station_link[this->station_path
						[this->end_station_][i]]
						[this->station_path
						[this->end_station_][i + 1]].line_name;
				}
			}
			cout << endl;

			flag_output = 1;
		}
	}

	if (!flag_output)
		cout << "Error: No ways!" << endl;
}