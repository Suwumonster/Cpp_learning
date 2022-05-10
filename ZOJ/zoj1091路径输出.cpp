#include <iostream>
#include <string>
#include <queue>
using namespace std;
int moves[8][2] = {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
typedef struct Node
{
	int x;
	int y;
	int moves;
}node;
node nd[8][8];
node change(string s)
{
	s[0] -= 'a';
	s[1] -= '1';
	node temp;
	temp.x = s[1];
	temp.y = s[0];
	temp.moves = 0;
	return temp;
}
int check(node n,int arr[][8])
{
	if(n.x >= 0 && n.x <= 7 && n.y >= 0 && n.y <= 7 && arr[n.x][n.y] != 1)
	{
		return 1;
	}
	return 0;
}
int bfs(node s,node e,int arr[][8])
{
	queue <node> q;
	q.push(s);
	nd[s.x][s.y].x = -1;
	nd[s.x][s.y].y = -1;
	while(!q.empty())
	{
		node temp = q.front();
		q.pop();
		arr[temp.x][temp.y] = 1;
		if(temp.x == e.x && temp.y == e.y)
		{
			return temp.moves;
		}
		temp.moves += 1;
		for(int i = 0; i < 8; i++)
		{
			temp.x += moves[i][0];
			temp.y += moves[i][1];
			if(check(temp,arr))
			{
				q.push(temp);
				nd[temp.x][temp.y].x = temp.x - moves[i][0];
				nd[temp.x][temp.y].y = temp.y - moves[i][1];
			}
			temp.x -= moves[i][0];
			temp.y -= moves[i][1];
		}
	}
}
void display(int x,int y)
{
	if(x == -1 && y == -1)
	{
		return;
	}
	display(nd[x][y].x,nd[x][y].y);
	cout << "(" << (char)(y + 'a') << "," << x + 1 << ")" << endl;
}
int main()
{
	string s1, s2;
	while(cin >> s1 >> s2)
	{
		node start = change(s1);
		node end = change(s2);
		int arr[8][8] = { 0 };
		int num = bfs(start,end,arr);
		cout << "To get from "<< s1 <<" to "<< s2 <<" takes "<< num <<" knight moves." << endl;
		display(end.x,end.y);
	}
	return 0;
}