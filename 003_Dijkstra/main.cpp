#include "../Map.h"
using namespace std;

struct Node
{
	int cos;
	pair<int, int> xoy;
	bool operator < (const Node& a) const { return cos > a.cos; }
};

int main()
{
	pair<int, int> buff;
	pair<int, int> start(1, 1);
	pair<int, int> end(End_I, End_II);
	Map[start.first][start.second] = 'S';
	Map[end.first][end.second] = 'E';
	cout << "Initial the map " << endl;
	for (auto &hang : Map)
	{
		for (char item : hang) cout << item << " ";
		cout << endl;
	}
	cout << endl;

	priority_queue<Node> que;
	Node stg;
	stg.cos = 0;
	stg.xoy = start;
	que.push(stg);
	map<pair<int, int>, pair<int, int>> path;
	map<pair<int, int>, int> cost_to_start;
	cost_to_start[start] = 0;
	int new_cost=0;

	while (!que.empty())
	{
		buff = que.top().xoy;
		if (buff == end)
		{
			cout << "BFS End !!" << endl;
			break;
		}
		que.pop();
		//Map[buff.first][buff.second] = ' ';

		new_cost = cost_to_start[buff] + 1;

		if (Down == 0 || Down == 'E')
		{
			cost_to_start[make_pair(buff.first + 1, buff.second)] = new_cost;
			stg.cos = new_cost;
			stg.xoy = make_pair(buff.first + 1, buff.second);
			que.push(stg);
			path[make_pair(buff.first + 1, buff.second)] = buff;
			if (Down == 'E') break;
			Down = '*';
		}
		if (Right == 0 || Right == 'E')
		{
			cost_to_start[make_pair(buff.first, buff.second + 1)] = new_cost;
			stg.cos = new_cost;
			stg.xoy = make_pair(buff.first, buff.second + 1);
			que.push(stg);
			path[make_pair(buff.first, buff.second + 1)] = buff;
			if (Right == 'E') break;
			Right = '*';
		}
		if (Up == 0 || Up == 'E')
		{
			cost_to_start[make_pair(buff.first - 1, buff.second)] = new_cost;
			stg.cos = new_cost;
			stg.xoy = make_pair(buff.first - 1, buff.second);
			que.push(stg);
			path[make_pair(buff.first - 1, buff.second)] = buff;
			if (Up == 'E') break;
			Up = '*';
		}
		if (Left == 0 || Left == 'E')
		{
			cost_to_start[make_pair(buff.first, buff.second - 1)] = new_cost;
			stg.cos = new_cost;
			stg.xoy = make_pair(buff.first, buff.second - 1);
			que.push(stg);
			path[make_pair(buff.first, buff.second - 1)] = buff;
			if (Left == 'E') break;
			Left = '*';
		}

		//for (auto &hang : Map)
		//{
		//	for (char item : hang) cout << item << " ";
		//	cout << endl;
		//}
		//cout << endl;

	}

	for (auto &hang : Map)
	{
		for (char item : hang) cout << item << " ";
		cout << endl;
	}
	cout << endl;

	buff = end;
	Map[end.first][end.second] = 'E';
	int cnt = 0;
	double dis = 0;
	while (1)
	{
		pair<int, int> dis_buff;
		dis_buff = path[buff];
		if (dis_buff == start)
		{
			Map[dis_buff.first][dis_buff.second] = 'S';
			break;
		}
		Map[dis_buff.first][dis_buff.second] = '-';
		cnt++;
		dis += sqrt(pow(dis_buff.first - buff.first, 2) + pow(dis_buff.second - buff.second, 2));
		buff = dis_buff;
	}

	int Search_cnt = 0;
	cout << "Path as following :" << endl;
	for (auto &hang : Map)
	{
		for (char item : hang) {
			if (item == '*') Search_cnt++;
			cout << item << " ";
		}
		cout << endl;
	}
	cout << "The step is : " << cnt << "  dis is : " << dis << "  Search step :" << Search_cnt << endl;



	system("pause");
	return 0;
}