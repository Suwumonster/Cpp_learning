#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//int main()
//{
//	int arr[3][3] = { {85,90,80},{65,70,75},{75,85,77} };//学生1（英语  高数   c++）  学生2（英语  高数   c++）  学生3  （英语  高数   c++）
//	int StdAverage[3] = {0};//学生平均分
//	int ProjAverage[3] = {0};//英语、高数、c++的平均分
//	int count;
//	for (count = 0; count < 3; count++)
//	{
//		StdAverage[0] += arr[0][count];//学生1
//		StdAverage[1] += arr[1][count];//学生2
//		StdAverage[2] += arr[2][count];//学生3
//		ProjAverage[0] += arr[count][0];//英语
//		ProjAverage[1] += arr[count][1];//高数
//		ProjAverage[2] += arr[count][2];//c++
//	}
//	for (count = 0; count < 3; count++)
//	{
//		cout << "StdAverage["<< count <<"] =" << StdAverage[count] / 3 << endl;
//		cout << "ProjAverage["<< count <<"] =" << ProjAverage[count] / 3 << endl;
//	}
//	return 0;
//}