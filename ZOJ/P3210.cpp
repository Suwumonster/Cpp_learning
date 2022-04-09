#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int isStack(stack <int> s1, int arr[], int n);
int isQueue(queue <int> q1, int arr[], int n);
int main()
{
	stack <int> s1;
	queue <int> q1;
	int t, n = 0;
	int i, j = 0;
	cin >> t;
	int arr1[2][100] = { 0 };
	for (j = 0; j < t; j++)
	{
		while (s1.size() != 0 && q1.size() != 0)
		{
			s1.pop();
			q1.pop();
		}
		int arr[100] = { 0 };
		cin >> n;
		for (i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			s1.push(temp);
			q1.push(temp);
		}
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		arr1[0][j] = isStack(s1, arr, n);
		arr1[1][j] = isQueue(q1, arr, n);
	}
	for (j = 0; j < t; j++)
	{
		if (arr1[0][j] == 1 && arr1[1][j] == 1)
		{
			cout << "both" << endl;
		}
		else if (arr1[0][j] == 1)
		{
			cout << "stack" << endl;
		}
		else if (arr1[1][j] == 1)
		{
			cout << "queue" << endl;
		}
		else
		{
			cout << "neither" << endl;
		}
	}
	return 0;
}
int isStack(stack <int> s1, int arr[], int n)
{
	int isstack = 1;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		int temp = s1.top();
		s1.pop();
		if (temp != arr[i])
		{
			isstack = 0;
			break;
		}
	}
	return isstack;
}
int isQueue(queue <int> q1, int arr[], int n)
{
	int isqueue = 1;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		int temp = q1.front();
		q1.pop();
		if (temp != arr[i])
		{
			isqueue = 0;
			break;
		}
	}
	return isqueue;
}
