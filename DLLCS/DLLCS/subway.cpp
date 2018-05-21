#include "stdafx.h"
using namespace std;

Subway::Subway()
{
	this->flag_gui = false;
	this->flag_exit = false;
	this->station_num_ = 0;
	this->transfer_par = 0;
	this->station_name = new string[STATION_NUM];
	this->station_link = new Link*[STATION_NUM];
	this->position = new Position[STATION_NUM];
	this->station_path = new int*[STATION_NUM];
	this->visit_station = new int[STATION_NUM];
	for (int i = 0; i < STATION_NUM; i++) // 除自身外一开始每个点都不可达
	{
		station_name[i] = "";
		this->visit_station[i] = 0;
		this->station_link[i] = new Link[STATION_NUM];
		this->station_path[i] = new int[STATION_NUM];

		for (int j = 0; j < STATION_NUM; j++)
		{
			station_path[i][j] = -1;  // 初值为-1，即没有路径
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
	fstream output_file("gui_print.txt", ios::out);
	if (!this->flag_gui)
		output_file.close();

	if (!read_file.is_open())
	{
		if (!this->flag_gui)
		{
			cout << "Error: Unable to open file correctly." << endl;
			exit(-1);
		}

		else
		{
			output_file << "Error" << endl;
			output_file << "Unable to open file correctly in beijing-subway.txt." << endl;
			output_file.close();
			this->flag_exit = true;
			return;
		}
	}
	bool flag_file = false;
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
			this->position[pos_station].x = pos_x;
			this->position[pos_station].y = pos_y;
			this->name_to_num[temp_str] = pos_station;
			this->station_num_++;
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
	if (this->flag_gui)
		output_file.close();
}

void Subway::GetTwoStation(string start_station, string end_station)
{
	fflush(stdout);
	fstream output_file("gui_print.txt", ios::out);
	if (!this->flag_gui)
		output_file.close();

	this->start_station_ = this->name_to_num[start_station];
	this->end_station_ = this->name_to_num[end_station];
	if (!this->start_station_ || !this->end_station_)
	{
		if (!this->flag_gui)
		{
			cout << "Error: 站名错误！" << endl;
			exit(-1);
		}
		else
		{
			output_file << "Error" << endl;
			output_file << "站名错误！" << endl;
			output_file.close();
			this->flag_exit = true;
			return;
		}
	}
	if (this->flag_gui)
		output_file.close();
}

void Subway::PrintStationPostion()
{
	fstream output_file("gui_print.txt", ios::out);

	output_file << this->position[this->start_station_].x
		<< " " << this->position[this->start_station_].y << endl;

	output_file.close();
}

void Subway::GetSingleStation(string start_station)
{
	fstream output_file("gui_print.txt", ios::out);
	if (!this->flag_gui)
		output_file.close();

	this->start_station_ = this->name_to_num[start_station];
	this->end_station_ = 0;

	if (!this->start_station_)
	{
		if (!this->flag_gui)
		{
			cout << "Error: 输入错误！" << endl;
			exit(-1);
		}
		else
		{
			output_file << "Error" << endl;
			output_file << "输入错误！" << endl;
			output_file.close();
			this->flag_exit = true;
			return;
		}
	}
	if (this->flag_gui)
		output_file.close();
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
			this->station_path[i][0] = this->start_station_;  // start_station_到i最短路径经过的第一个顶点
			this->station_path[i][1] = i;  // start_station到i最短路径经过的第二个顶点
		}
	}

	/* 核心语句 */
	for (int i = 0; i < STATION_NUM - 1; i++)
	{
		int min = INF;  // 记录最小dis[i]
		int u;  // 记录小dis[i]的点
		for (int j = 0; j < STATION_NUM; j++)
		{
			if (book[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		if (u == this->start_station_)
			continue;
		for (int v = 0; v < STATION_NUM; v++)
		{
			if (v == this->start_station_)
				continue;
			if (!book[v] && this->station_link[u][v].value < INF
				&& dis[v] > dis[u] + this->station_link[u][v].value)
			{
				dis[v] = dis[u] + this->station_link[u][v].value;

				for (int i = 0; i < STATION_NUM; i++)
				{
					this->station_path[v][i] = this->station_path[u][i];
					if (this->station_path[v][i] == -1)
					{
						this->station_path[v][i] = v;
						break;
					}
				}

				/* 是否为换乘优化模式 */
				if (this->transfer_par)
				{
					dis[u] = 0;
					for (int i = 0; i < STATION_NUM; i++)
					{
						if (i != 0 && this->station_path[u][i - 1] > -1
							&& this->station_path[u][i + 1] > -1)
						{
							dis[u] += this->station_link[this->station_path[u][i]][this->station_path[u][i]].value;
							if (this->station_link[this->station_path[u][i - 1]]
								[this->station_path[u][i]].line_name
								!= this->station_link[this->station_path[u][i]]
								[this->station_path[u][i + 1]].line_name)
								dis[u] += this->transfer_par;
						}
					}
					dis[v] = dis[u] + this->station_link[u][v].value;
				}
			}
		}
	}
}

void Subway::PrintPath()
{
	int flag_output = 0;
	this->station_path_num_ = 0;

	fstream output_file("gui_print.txt", ios::out);
	if (!this->flag_gui)
		output_file.close();

	for (int i = 0; i < STATION_NUM; i++)
	{
		if (this->station_path[this->end_station_][i] > -1)
			this->station_path_num_++;
	}
	if (!this->flag_gui)
		cout << this->station_path_num_ << endl;

	for (int i = 0; i < STATION_NUM; i++)
	{
		if (this->station_path[this->end_station_][i] > -1)
		{
			if (!this->flag_gui)
				cout << this->station_name[this->station_path[end_station_][i]];
			else
			{
				output_file << this->position[this->station_path[end_station_][i]].x
					<< " " << this->position[this->station_path[end_station_][i]].y << endl;
			}

			/* 当前后两条线路名不同说明换乘 */
			if (!this->flag_gui && i != 0 && this->station_path[this->end_station_][i - 1] > -1
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
			if (!this->flag_gui)
				cout << endl;

			flag_output = 1;
		}
	}

	if (!flag_output)
	{
		if (!this->flag_gui)
			cout << "Error: No ways!" << endl;
		else
		{
			output_file << "Error" << endl;
			output_file << "No ways!" << endl;
			output_file.close();
		}
	}
}

void Subway::PrintBeijingSubwayLine(string subway_line)
{
	fstream output_file("gui_print.txt", ios::out);
	if (!this->flag_gui)
		output_file.close();

	if (subway_line == "1号线")
	{
		int station[] = {
			1 ,2 ,3 ,4 ,5 ,6 ,
			7, 8, 9 ,10, 11, 12 ,
			13 ,14 ,15, 16, 17 ,18 ,
			19 ,20 ,21 ,22, 23, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "2号线")
	{
		int station[] = {
			24, 25, 26, 27, 28,
			29, 30, 18, 31, 32,
			33, 34, 35, 36, 12,
			37, 38, 39, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "4号线/大兴线"
		|| subway_line == "4号线" || subway_line == "大兴线")
	{
		int station[] = {
			40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
			50, 39, 51, 52, 53, 54, 13, 35, 55, 56,
			57, 58, 59, 60, 61, 62, 63, 64, 65, 66,
			67, 68, 69, 70, 71, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "5号线")
	{
		int station[] = {
			72, 73, 74, 75, 76, 32, 17,
			77, 78, 79, 80, 27, 81, 82,
			83, 84, 85, 86, 87, 88, 89,
			90, 91, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "6号线")
	{
		int station[] = {
			92, 93, 94, 95, 96, 38, 52, 97,
			98, 78, 30, 99, 100, 101, 102,
			103, 104, 105, 106, 107, 108, 109,
			110, 111, 112, 113, 114, 115, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "7号线")
	{
		int station[] = {
			116, 117, 118, 119, 55, 120,
			121, 122, 76, 123, 124, 125,
			126, 127, 128, 129, 130, 131,
			132, 133, 134, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "8号线")
	{
		int station[] = {
			135, 136, 137, 138, 139, 140,
			141, 142, 143, 144, 145, 146,
			147, 148, 149, 25, 150, 98, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "9号线")
	{
		int station[] = {
			151, 152, 153, 154, 155,
			156, 157, 158, 116, 9,
			159, 95, 49, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "10号线")
	{
		int station[] = {
			160, 161, 46, 162, 163, 164, 165, 166,
			147, 167, 83, 168, 169, 170, 171, 172,
			173, 100, 174, 20, 125, 175, 176, 177,
			178, 179, 72, 180, 181, 182, 59, 183,
			184, 185, 186, 187, 188, 157, 189, 8,
			190, 93, 191, 192, 193, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "13号线")
	{
		int station[] = {
			39, 194, 163, 195, 196,
			197, 198, 199, 139, 88,
			200, 201, 168, 202, 203,
			28, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "14号线东线")
	{
		int station[] = {
			204, 205, 206, 207, 208, 209, 210, 211,
			212, 213, 214, 101, 21, 126, 291, 292,
			177, 293, 74, 294, 295, 296, 57, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "15号线")
	{
		int station[] = {
			215, 216, 217, 218, 219,
			220, 221, 222, 223, 224,
			225, 207, 201, 226, 85,
			227, 145, 228, 229, 230, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "八通线")
	{
		int station[] = {
			22, 23, 231, 232, 233,
			234, 235, 236, 237, 238,
			239, 240, 241, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "昌平线")
	{
		int station[] = {
			281, 280, 279, 278, 277, 242,
			243, 244, 245, 135, 246, 197,-1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "亦庄线")
	{
		int station[] = {
			72, 247, 248, 249, 250,
			251, 252, 253, 254, 255,
			256, 257, 258, 259, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "房山线")
	{
		int station[] = {
			282, 260, 261, 262, 263, 264,
			265, 266, 267, 268, 269, 151, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "机场线")
	{
		int station[] = { 28, 170, 270, 271, -1 };

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "14号线西线")
	{
		int station[] = { 276, 275, 274, 273, 272, 156, 188, -1 };

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "16号线")
	{
		int station[] = {
			305, 304, 303, 302, 301,
			300, 299, 298, 297, 42, -1
		};

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "西郊线")
	{
		int station[] = { 310, 309, 308, 307, 306, 160, -1 };

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "S1线")
	{
		int station[] = { 317, 316, 315, 314, 313, 312, 311, 1, -1 };

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}

	if (subway_line == "燕房线")
	{
		int station[] = { 290, 289, 288, 287, 286, 285, 284, 283, 282, -1 };

		if (!this->flag_gui)
			cout << subway_line << endl;
		for (int i = 0; station[i] != -1; i++)
		{
			if (!this->flag_gui)
				cout << this->station_name[station[i]] << endl;
			else
			{
				output_file << this->position[station[i]].x
					<< " " << this->position[station[i]].y << endl;
			}
		}
		if (this->flag_gui)
			output_file.close();

		return;
	}
	if (!this->flag_gui)
		cout << "Error: 线路错路！" << endl;
	else
	{
		output_file << "Error" << endl;
		output_file << "线路错误！" << endl;
		output_file.close();
	}
}

void Subway::Transfer()
{
	this->transfer_par = 2;
}

void Subway::ResetStationPath()
{
	for (int i = 0; i < STATION_NUM; i++)
	{
		for (int j = 0; j < STATION_NUM; j++)
		{
			this->station_path[i][j] = -1;
		}
	}
}

void Subway::AddPath()
{
	this->ResetStationPath();
	this->Dijkstra();

	bool first_flag = true;
	int station_temp;
	int temp1, temp2;
	for (int i = 0; i < STATION_NUM; i++)
	{
		station_temp = this->station_path[this->end_station_][i];
		if (station_temp > -1)
		{
			temp1 = station_temp;
			if (this->visit_station[station_temp] == 0
				&& station_temp <= this->station_num_)
			{
				this->visit_num_--;
				this->visit_station[station_temp] = 1;
			}
			if (!first_flag)
				this->path_list[this->path_list_num++] = station_temp;

			temp2 = station_temp;
			first_flag = false;
		}
	}
}

void Subway::Traverse()
{
	fstream output_file("beijing_subway_traverse.txt", ios::out);
	fstream output_file2("gui_print.txt", ios::out);
	if (this->flag_gui)
		output_file.close();
	else
		output_file2.close();

	this->path_list = new int[3 * STATION_NUM];
	this->path_list_num = 0;
	this->visit_num_ = this->station_num_;
	int from_station = this->start_station_;
	this->path_list[this->path_list_num++] = from_station;
	int start_ = from_station;

	while (this->visit_num_ > 0)
	{
		for (int i = 1; i <= this->station_num_; i++)
		{
			if (this->visit_station[i] != 1)
			{
				this->start_station_ = from_station;
				this->end_station_ = i;
				this->AddPath();  // 在添加路径时注意记录访问点数
				from_station = i;
				break;
			}
		}
	}

	this->start_station_ = from_station;
	this->end_station_ = start_;
	this->AddPath();

	for (int i = 0; i < this->path_list_num; i++)
	{
		if (!this->flag_gui)
			output_file << this->station_name[this->path_list[i]] << " ";
		else
		{
			output_file2 << this->position[this->path_list[i]].x
				<< " " << this->position[this->path_list[i]].y << endl;
		}

		if (!this->flag_gui && i != 0 && this->path_list[i - 1] > -1
			&& this->path_list[i + 1] > -1)
		{
			if (i != this->path_list_num - 1
				&& this->station_link[this->path_list[i - 1]]
				[this->path_list[i]].line_name
				!= this->station_link[this->path_list[i]]
				[this->path_list[i + 1]].line_name)
				output_file << " 换乘" << this->station_link[this->path_list[i]][this->path_list[i + 1]].line_name;
		}
		if (!this->flag_gui)
			output_file << endl;
	}

	if (!this->flag_gui)
		output_file.close();
	else
		output_file2.close();
}

void Subway::CheckTraverse(string file_name)
{
	fstream read_file(file_name, ios::in);

	if (!read_file.is_open())
	{
		cout << "Error: Unable to open file correctly." << endl;
		exit(-1);
	}

	this->path_list = new int[3 * STATION_NUM];
	this->path_list_num = 0;
	string str_line, temp_str;
	int pos_space;
	this->visit_num_ = 0;

	while (getline(read_file, str_line))
	{
		pos_space = 0;
		while (str_line[++pos_space] != ' ');
		temp_str = str_line.substr(0, pos_space);

		int temp_str_num = this->name_to_num[temp_str];

		if (this->visit_station[temp_str_num] == 0)
		{
			this->visit_station[temp_str_num]++;
			this->visit_num_++;
		}

		this->path_list[this->path_list_num++] = temp_str_num;
	}
	read_file.close();

	bool false_flag = true;
	for (int i = 1; i <= this->station_num_; i++)
	{
		if (this->visit_station[i] == 0)
		{
			if (false_flag)
			{
				cout << "False: There are omissions." << endl;
				false_flag = false;
			}
			cout << this->station_name[i] << endl;
		}
	}

	bool error_flag = true;
	for (int i = 1; i <= this->path_list_num - 2; i++)
	{
		int from = this->path_list[i];
		int to = this->path_list[i + 1];
		if (this->station_link[from][to].value == INF)
		{
			if (error_flag)
			{
				cout << "Error:" << endl;
				error_flag = false;
			}
			cout << "From: " << this->station_name[from] << " ";
			cout << "To: " << this->station_name[to] << endl;
		}
	}

	if ((!false_flag) || (!error_flag))
		exit(-1);
	if (this->visit_num_ == this->station_num_)
		cout << "True!" << endl;
	else  //  当没有进行/a操作时文本应为空
		cout << "NULL!" << endl;
}