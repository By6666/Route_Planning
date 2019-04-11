#include "../Map.h"
using namespace std;

struct Node
{
	double dis;
	pair<int, int> xoy;
	bool operator < (const Node& a) const { return dis > a.dis; }
};

double dis_to_end(pair<int, int> cur, pair<int, int> end)
{
	//return sqrt(pow((cur.first - end.first), 2) + pow((cur.second - end.second), 2));
	return pow((cur.first - end.first), 2) + pow((cur.second - end.second), 2);
	//return abs(cur.first - end.first) +abs(cur.second - end.second);

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
	stg.dis = dis_to_end(start, end);
	stg.xoy = start;
	que.push(stg);
	map<pair<int, int>, pair<int, int>> path;

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

		if (Up == 0 || Up == 'E')
		{
			stg.xoy = make_pair(buff.first - 1, buff.second);
			stg.dis = dis_to_end(make_pair(buff.first - 1, buff.second), end);
			que.push(stg);
			path[make_pair(buff.first - 1, buff.second)] = buff;
			if (Up == 'E') break;
			Up = '*';
		}
		if (Up != 1 && Right != 1 && Right_Up == 0 && Right_Up != 'E')
		{
			stg.xoy = make_pair(buff.first - 1, buff.second + 1);
			stg.dis = dis_to_end(make_pair(buff.first - 1, buff.second + 1), end);
			que.push(stg);
			path[make_pair(buff.first - 1, buff.second + 1)] = buff;
			Right_Up = '*';
		}
		if (Right == 0 || Right == 'E')
		{
			stg.xoy = make_pair(buff.first, buff.second + 1);
			stg.dis = dis_to_end(make_pair(buff.first, buff.second + 1), end);
			que.push(stg);
			path[make_pair(buff.first, buff.second + 1)] = buff;
			if (Right == 'E') break;
			Right = '*';
		}
		if (Down != 1 && Right != 1 && Right_Down == 0 && Right_Down != 'E')
		{
			stg.xoy = make_pair(buff.first + 1, buff.second + 1);
			stg.dis = dis_to_end(make_pair(buff.first + 1, buff.second + 1), end);
			que.push(stg);
			path[make_pair(buff.first + 1, buff.second + 1)] = buff;
			Right_Down = '*';
		}
		if (Down == 0 || Down == 'E')
		{
			stg.xoy = make_pair(buff.first + 1, buff.second);
			stg.dis = dis_to_end(make_pair(buff.first + 1, buff.second), end);
			que.push(stg);
			path[make_pair(buff.first + 1, buff.second)] = buff;
			if (Down == 'E') break;
			Down = '*';
		}
		if (Down != 1 && Left != 1 && Left_Down == 0 && Left_Down != 'E')
		{
			stg.xoy = make_pair(buff.first + 1, buff.second - 1);
			stg.dis = dis_to_end(make_pair(buff.first + 1, buff.second - 1), end);
			que.push(stg);
			path[make_pair(buff.first + 1, buff.second - 1)] = buff;
			Left_Down = '*';
		}
		if (Left == 0 || Left == 'E')
		{
			stg.xoy = make_pair(buff.first, buff.second - 1);
			stg.dis = dis_to_end(make_pair(buff.first, buff.second - 1), end);
			que.push(stg);
			path[make_pair(buff.first, buff.second - 1)] = buff;
			if (Left == 'E') break;
			Left = '*';
		}

		if (Up != 1 && Left != 1 && Left_Up == 0 && Left_Up != 'E')
		{
			stg.xoy = make_pair(buff.first - 1, buff.second - 1);
			stg.dis = dis_to_end(make_pair(buff.first - 1, buff.second - 1), end);
			que.push(stg);
			path[make_pair(buff.first - 1, buff.second - 1)] = buff;
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