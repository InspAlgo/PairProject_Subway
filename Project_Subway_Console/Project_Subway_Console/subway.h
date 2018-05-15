#pragma once
#define INF 999
#define STATION_NUM 320
using namespace std;

struct Link
{
	int value;  // Ȩֵ���ڻ���Ҫ����ȨֵΪ1��ʵ�����Ӧ��ʱ��ΪȨֵ
	string line_name;  // ����������
};

struct Stack
{
	int top;
	int *station;
};

struct Station
{
	int last_station = -1;
	string line;
	string name;
};

struct SubLine
{
	string line_name;
	vector<string> stations;
	bool is_circle = false;
	bool is_two_dir = true;
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
	void ResetValue(string order);
	void Fleury();
	void Transfer();
private:
	void FleuryDFS(int to_station);
	void FleuryMain(int to_station);
	string *station_name;
	map<string, int>name_to_num;  // ���ڵ�����ӳ�䵽�ڵ���
	Link **station_link;
	Stack station_stack;
	int station_num_;
	int **station_path;  // path[][]=-1��ʾû��·����path[v][i]����Ǵ�v0��v��ǰ��õ����·�������ĵ�i+1������(���Ǵ�ӡ���·���Ĺؼ�)
						 // ��v0��v�����·����Ϊpath[v][0]��p[v][j]ֱ��path[v][j]=-1,·����ӡ��ϡ�
	int station_path_num_;
	int start_station_, end_station_;
	int transfer_par;  // ����Ӱ�����
};