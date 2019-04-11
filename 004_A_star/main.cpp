#include "../Map.h"
using namespace std;

struct Node
{
	double cos;
	pair<int, int> xoy;
	bool operator < (const Node& a) const { return cos > a.cos; }
};

double dis_to_end(pair<int, int> cur, pair<int, int> end)
{
	//return sqrt(pow((cur.first - end.first), 2) + pow((cur.second - end.second), 2));
	return pow((cur.first - end.first), 2) + pow((cur.second - end.second), 2);
	//return abs(cur.first - end.first) + abs(cur.second - end.second);
}


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
	int new_cost = 0;

	while (!que.empty())
	{
		buff = que.top().xoy;
		if (buff == end)
		{
			cout << "BFS End !!" << endl;
			break;
		}
		que.pop();

		new_cost = cost_to_start[buff] + 1;

		if (Up != 1 && Up != 'S')
		{
			if (cost_to_start.find(make_pair(buff.first - 1, buff.second)) == cost_to_start.end() || new_cost < cost_to_start[make_pair(buff.first - 1, buff.second)])
			{
				cost_to_start[make_pair(buff.first - 1, buff.second)] = new_cost;
				stg.cos = new_cost + dis_to_end(make_pair(buff.first - 1, buff.second), end);
				stg.xoy = make_pair(buff.first - 1, buff.second);
				que.push(stg);
				path[make_pair(buff.first - 1, buff.second)] = buff;
			}
			if (Up == 'E') break;
			Up = '*';
		}
		if (Up != 1 && Right != 1 && Right_Up != 1 && Right_Up != 'S' && Right_Up != 'E')
		{
			if (cost_to_start.find(make_pair(buff.first - 1, buff.second + 1)) == cost_to_start.end() || new_cost < cost_to_start[make_pair(buff.first - 1, buff.second + 1)])
			{
				cost_to_start[make_pair(buff.first - 1, buff.second + 1)] = new_cost;
				stg.cos = new_cost + dis_to_end(make_pair(buff.first - 1, buff.second + 1), end);
				stg.xoy = make_pair(buff.first - 1, buff.second + 1);
				que.push(stg);
				path[make_pair(buff.first - 1, buff.second + 1)] = buff;
			}
			Right_Up = '*';
		}
		if (Right != 1 && Right != 'S')
		{
			if (cost_to_start.find(make_pair(buff.first, buff.second + 1)) == cost_to_start.end() || new_cost < cost_to_start[make_pair(buff.first, buff.second + 1)])
			{
				cost_to_start[make_pair(buff.first, buff.second + 1)] = new_cost;
				stg.cos = new_cost + dis_to_end(make_pair(buff.first, buff.second + 1), end);
				stg.xoy = make_pair(buff.first, buff.second + 1);
				que.push(stg);
				path[make_pair(buff.first, buff.second + 1)] = buff;
			}

			if (Right == 'E') break;
			Right = '*';
		}
		if (Down != 1 && Down != 'S')
		{
			if (cost_to_start.find(make_pair(buff.first + 1, buff.second)) == cost_to_start.end() || new_cost < cost_to_start[make_pair(buff.first + 1, buff.second)])
			{
				cost_to_start[make_pair(buff.first + 1, buff.second)] = new_cost;
				stg.cos = new_cost + dis_to_end(make_pair(buff.first + 1, buff.second), end);
				stg.xoy = make_pair(buff.first + 1, buff.second);
				que.push(stg);
				path[make_pair(buff.first + 1, buff.second)] = buff;
			}
			if (Down == 'E') break;
			Down = '*';
		}
		if (Down != 1 && Right != 1 && Right_Down != 1 && Right_Down != 'S'&& Right_Down != 'E')
		{
			if (cost_to_start.find(make_pair(buff.first + 1, buff.second + 1)) == cost_to_start.end() || new_cost < cost_to_start[make_pair(buff.first + 1, buff.second + 1)])
			{
				cost_to_start[make_pair(buff.first + 1, buff.second + 1)] = new_cost;
				stg.cos = new_cost + dis_to_end(make_pair(buff.first + 1, buff.second + 1), end);
				stg.xoy = make_pair(buff.first + 1, buff.second + 1);
				que.push(stg);
				path[make_pair(buff.first + 1, buff.second + 1)] = buff;
			}
			Right_Down = '*';
		}

		if (Left != 1 && Down != 1 && Left_Down != 1 && Left_Down != 'S'&&Left_Down != 'E')
		{
			if (cost_to_start.find(make_pair(buff.first + 1, buff.second - 1)) == cost_to_start.end() || new_cost < cost_to_start[make_pair(buff.first + 1, buff.second - 1)])
			{
				cost_to_start[make_pair(buff.first + 1, buff.second - 1)] = new_cost;
				stg.cos = new_cost + dis_to_end(make_pair(buff.first + 1, buff.second - 1), end);
				stg.xoy = make_pair(buff.first + 1, buff.second - 1);
				que.push(stg);
				path[make_pair(buff.first + 1, buff.second - 1)] = buff;
			}
			Left_Down = '*';
		}

		if (Left != 1 && Left != 'S')
		{
			if (cost_to_start.find(make_pair(buff.first, buff.second - 1)) == cost_to_start.end() || new_cost < cost_to_start[make_pair(buff.first, buff.second - 1)])
			{
				cost_to_start[make_pair(buff.first, buff.second - 1)] = new_cost;
				stg.cos = new_cost + dis_to_end(make_pair(buff.first, buff.second - 1), end);
				stg.xoy = make_pair(buff.first, buff.second - 1);
				que.push(stg);
				path[make_pair(buff.first, buff.second - 1)] = buff;
			}

			if (Left == 'E') break;
			Left = '*';
		}

		if (Left != 1 && Up != 1 && Left_Up != 1 && Left_Up != 'S'&&Left_Up != 'E')
		{
			if (cost_to_start.find(make_pair(buff.first - 1, buff.second - 1)) == cost_to_start.end() || new_cost < cost_to_start[make_pair(buff.first - 1, buff.second - 1)])
			{
				cost_to_start[make_pair(buff.first - 1, buff.second - 1)] = new_cost;
				stg.cos = new_cost + dis_to_end(make_pair(buff.first - 1, buff.second - 1), end);
				stg.xoy = make_pair(buff.first - 1, buff.second - 1);
				que.push(stg);
				path[make_pair(buff.first - 1, buff.second - 1)] = buff;
			}
			Left_Up = '*';
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
	while (1)
	{
		buff = path[buff];
		if (buff == start)
		{
			Map[buff.first][buff.second] = 'S';
			break;
		}
		Map[buff.first][buff.second] = '-';
	}

	cout << "Path as following :" << endl;
	for (auto &hang : Map)
	{
		for (char item : hang) cout << item << " ";
		cout << endl;
	}
	cout << endl;


	system("pause");
	return 0;
}