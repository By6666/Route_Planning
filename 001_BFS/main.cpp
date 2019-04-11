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

		if (Up == 0 || Up == 'E')
		{
			que.push(make_pair(buff.first - 1, buff.second));
			path[make_pair(buff.first - 1, buff.second)] = buff;
			if (Up == 'E') break;
			Up = '*';
		}
		if (Left == 0 || Left == 'E')
		{
			que.push(make_pair(buff.first, buff.second - 1));
			path[make_pair(buff.first, buff.second - 1)] = buff;
			if (Left == 'E') break;
			Left = '*';
		}
		if (Right == 0 || Right == 'E')
		{
			que.push(make_pair(buff.first, buff.second + 1));
			path[make_pair(buff.first, buff.second + 1)] = buff;
			if (Right == 'E') break;
			Right = '*';
		}
		if (Down == 0 || Down == 'E')
		{
			que.push(make_pair(buff.first + 1, buff.second));
			path[make_pair(buff.first + 1, buff.second)] = buff;
			if (Down == 'E') break;
			Down = '*';
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
		Map[buff.first][buff.second] = '=';
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