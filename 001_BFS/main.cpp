#include "../Map.h"
using namespace std;


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

	queue<pair<int,int>> que;
	que.push(start);
	map<pair<int, int>, pair<int, int>> path;

	while (!que.empty())
	{
		buff = que.front();
		if (buff == end)
		{
			cout << "BFS End !!" << endl;
			break;
		}
		que.pop();
		//Map[buff.first][buff.second] = ' ';
		if (Down == 0 || Down == 'E')
		{
			que.push(make_pair(buff.first + 1, buff.second));
			path[make_pair(buff.first + 1, buff.second)] = buff;
			if (Down == 'E') break;
			Down = '*';
		}
		if (Right == 0 || Right == 'E')
		{
			que.push(make_pair(buff.first, buff.second + 1));
			path[make_pair(buff.first, buff.second + 1)] = buff;
			if (Right == 'E') break;
			Right = '*';
		}
		if (Right != 1 && Down != 1 && Right_Down == 0 && Right_Down != 'E')
		{
			que.push(make_pair(buff.first + 1, buff.second + 1));
			path[make_pair(buff.first + 1, buff.second + 1)] = buff;
			Right_Down = '*';
		}
		if (Up == 0 || Up == 'E')
		{
			que.push(make_pair(buff.first - 1, buff.second));
			path[make_pair(buff.first - 1, buff.second)] = buff;
			if (Up == 'E') break;
			Up = '*';
		}
		if (Right != 1 && Up != 1 && Right_Up == 0 && Right_Up != 'E')
		{
			que.push(make_pair(buff.first - 1, buff.second + 1));
			path[make_pair(buff.first - 1, buff.second + 1)] = buff;
			Right_Up = '*';
		}
		if (Left != 1 && Down != 1 && Left_Down == 0 && Left_Down != 'E')
		{
			que.push(make_pair(buff.first + 1, buff.second - 1));
			path[make_pair(buff.first + 1, buff.second - 1)] = buff;
			Left_Down = '*';
		}

		if (Left == 0 || Left == 'E')
		{
			que.push(make_pair(buff.first, buff.second - 1));
			path[make_pair(buff.first, buff.second - 1)] = buff;
			if (Left == 'E') break;
			Left = '*';
		}
		if (Left != 1 && Up != 1 && Left_Up == 0 && Left_Up != 'E')
		{
			que.push(make_pair(buff.first - 1, buff.second - 1));
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