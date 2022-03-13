#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
using namespace std;
void encrypt(char str1[]);
void decrypt(char str2[]);
int main()
{
	char str1[80];
	char str2[80];
	fstream f;
	f.open("d:\\date.dat", ios::out | ios::binary);
	cin.getline(str1, 80, '#');
	encrypt(str1);
	f << str1;
	f.close();
	f.open("d:\\date.dat", ios::in | ios::binary);
	f.getline(str2, 80);
	decrypt(str2);
	cout << str2 << endl;
	f.close();
	return 0;
}
void encrypt(char str1[])
{
	int i = 0;
	for (i = 0; str1[i] != '\0'; i++)
	{
		if ( (str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] >= 'a' && str1[i] <= 'z') )
		{
			if ( (str1[i] >= 'W' && str1[i] <= 'Z') || str1[i] >= 'w')
			{
				str1[i] -= 22;
			}
			else
			{
				str1[i] += 4;
			}
		}
	}
}
void decrypt(char str2[])
{
	int i = 0;
	for (i = 0; str2[i] != '\0'; i++)
	{
		if ((str2[i] >= 'A' && str2[i] <= 'Z') || (str2[i] >= 'a' && str2[i] <= 'z'))
		{
			if ( (str2[i] >= 'A' && str2[i] <= 'D') || (str2[i] >= 'a' && str2[i] <= 'd') )
			{
				str2[i] += 22;
			}
			else
			{
				str2[i] -= 4;
			}
		}
	}
}