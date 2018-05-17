#pragma once
#define INF 999
#define STATION_NUM 320
using namespace std;

struct Link
{
	int value;  // 权值，在基本要求中权值为1，实际情况应以时间为权值
	string line_name;  // 地铁线名称
};

class Subway
{
public:
	Subway();
	void ReadFile();
	void Dijkstra();
	void PrintPath();
	void GetTwoStation(string start_station, string end_station);
	void GetSingleStation(string start_station);
	void PrintBeijingSubwayLine(string subway_line);
	void Transfer();
	void Traverse();
	void CheckTraverse(string file_name);
private:
	void AddPath();
	void ResetStationPath();
	string *station_name;
	map<string, int>name_to_num;  // 将节点名称映射到节点编号
	Link **station_link;
	int *path_list;
	int path_list_num;
	int station_num_;
	int **station_path;  // path[][]=-1表示没有路径，path[v][i]存的是从v0到v当前求得的最短路径经过的第i+1个顶点(这是打印最短路径的关键)
						 // 则v0到v的最短路径即为path[v][0]到p[v][j]直到path[v][j]=-1,路径打印完毕。
	int station_path_num_;
	int start_station_, end_station_;
	int transfer_par;  // 换乘影响参数
	int visit_num_;
	int *visit_station;
};