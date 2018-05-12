#pragma once
#define INF 9999999
#define STATION_NUM 300
using namespace std;

struct Link
{
	int value;
	string line_name;
};

class Subway
{
public:
	Subway();
	void ReadFile();
	void Dijkstra();
	void PrintPath();
	void GetTwoStation(string start_station, string end_station);
private:
	string *station_name;
	map<string, int>name_to_num;
	Link **station_link;
	int **station_path;
	int station_path_num_;
	int start_station_, end_station_;
};