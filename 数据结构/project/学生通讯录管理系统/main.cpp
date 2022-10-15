#define _CRT_SECURE_NO_WARNINGS 1

// 项目作者：suwu 学号：20212121013
// 项目最后修改时间： 2022.10.14
// 单人完成此项目 无合作者

#include "stu_con.h"

// 函数名：menu
// 函数参数：无
// 返回值：空
// 作用：打印总菜单
void menu()
{
	cout << "*************************************************************" << endl;
	cout << "****                 学生通讯录管理系统                  ****" << endl;
	cout << "****     1.新建一个通讯录         2.新增学生             ****" << endl;
	cout << "****     3.按位置号插入学生       4.按学号删除学生       ****" << endl;
	cout << "****     5.按学号修改学生信息     6.按学号排序显示学生   ****" << endl;
	cout << "****     7.按学号查找学生         8.显示全部学生信息     ****" << endl;
	cout << "****     9.读取文件中学生信息     10.把学生信息写入文件  ****" << endl;
	cout << "****                       11.退出                       ****" << endl;
	cout << "*************************************************************" << endl;
}


int main()
{
	int input = 0;//用于输入主菜单选项
	int id = 0;//用于输入学号
	STU* head = 0;//通讯录首元节点
	STU* tmp = 0;//接收 查找到的学生结点
	unsigned int locat = 0;
	do
	{
		menu();
		cout << "请按序号选择：";
		cin >> input;
		switch (input)
		{
			case 1://新建一个通讯录
				new_contact(head);
				head = 0;
				cout << "新建成功！" << endl;
				break;

			case 2://新增学生
				add_contact(head);
				cout << "增加成功！" << endl;
				break;

			case 3://按位置号插入学生
				cout << "请输入要插入的位置号:";
				cin >> locat;
				insert_contact(head, locat);
				cout << "插入成功！" << endl;
				break;

			case 4://按学号删除学生
				id = 0;
				cout << "输入要删除学生的学号:";
				cin >> id;
				if (del_student(head, id))
				{
					cout << "删除成功！" << endl;
				}
				else
				{
					cout << "删除失败！" << endl;
				}
				break;

			case 5://按学号修改学生信息
				id = 0;
				cout << "输入要修改的学生的学号:";
				cin >> id;
				tmp = search_contact(head, id);
				if (tmp != 0)
				{
					revise_contact(tmp);
				}
				else
				{
					cout << "修改失败！通讯录无此人！" << endl;
				}
				break;

			case 6://按学号排序并显示所有学生
				sort_contact(head, 0);
				show_contact(head);
				break;

			case 7://按学号查找学生
				id = 0;
				cout << "输入要查找的学生的学号:";
				cin >> id;
				tmp = search_contact(head, id);
				if (tmp != 0)
				{
					cout << "查找成功！" << endl;
					show_student(tmp);
				}
				else
				{
					cout << "查找失败！列表无此人！" << endl;
				}
				break;

			case 8://显示全部学生信息
				show_contact(head);
				break;

			case 9://读取文件中学生信息
				readfile_contact(head);
				break;

			case 10://把学生信息写入文件
				whitefile_contact(head);
				break;

			case 0://退出程序
				whitefile_contact(head);
				cout << "退出成功！" << endl;
				break;

			default:
				cout << "输入错误请重新输入！" << endl;
				break;
		}
	} while (input != 11);
	return 0;
}