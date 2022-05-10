#include <iostream>
#include <queue>
using namespace std;
char arr[30][30][30] = { 0 };
int moves[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
int l, r, c;
typedef struct NODE
{
	int z;
	int x;
	int y;
	int movenum;
}node;
int check(node temp)
{
	if (temp.x < r && temp.x >= 0 && temp.y < c && temp.y >= 0 && temp.z < l && temp.z >= 0 && arr[temp.z][temp.x][temp.y] != '#' )
	{
		return 1;
	}
	return 0;
}
int BFS(node s, node e)
{
	queue <node> q;
	q.push(s);
	while (!q.empty())
	{
		node temp = q.front();
		q.pop();
		if (temp.x == e.x && temp.y == e.y && temp.z == e.z)
		{
			return temp.movenum;
		}
		temp.movenum += 1;
		for (int i = 0; i < 6; i++)
		{
			temp.z += moves[i][0];
			temp.x += moves[i][1];
			temp.y += moves[i][2];
			if (check(temp))
			{
				arr[temp.z][temp.x][temp.y] = '#';
				q.push(temp);
			}
			temp.z -= moves[i][0];
			temp.x -= moves[i][1];
			temp.y -= moves[i][2];
		}
	}
	return -1;
}
int main()
{
	node start, end;
	while (cin >> l >> r >> c)
	{
		if (l == 0 && r == 0 && c == 0)
		{
			break;
		}
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				for (int k = 0; k < 30; k++)
				{
					arr[i][j][k] = 0;
				}
			}
		}
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c ; k++)
				{
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S')
					{
						start.z = i;
						start.x = j;
						start.y = k;
						start.movenum = 0;
					}
					else if (arr[i][j][k] == 'E')
					{
						end.z = i;
						end.x = j;
						end.y = k;
						end.movenum = 0;
					}
				}
			}
		}
		int num =BFS(start, end);
		if (num == -1)
		{
			cout << "Trapped!" << endl;
		}
		else
		{
			cout << "Escaped in "<< num <<" minute(s)." << endl;
		}
	}
	return 0;
}