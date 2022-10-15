#pragma once

// 项目作者：suwu 学号：20212121013
// 项目最后修改时间： 2022.10.14
// 单人完成此项目 无合作者

#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;


typedef struct DATE//出生年月日
{
	int year;
	int month;
	int day;
}DATE;


typedef struct STU//学生信息结点
{
	int id;
	char name[20];
	DATE birth;
	char sex[20];
	char address[20];
	float coordinate_x;
	float coordinate_y;
	struct STU* next;
}STU;

// 函数名：new_contact
// 函数参数：一个，ps 接收 通讯录首元结点
// 返回值：空
// 作用：建立一个新的通讯录，舍弃旧的通讯录。实质上是调用通讯录释放函数delete_contact
//		 将每个结点释放，避免内存泄露。
// PS:因为这个函数在该项目调用不多，所以将 保持首元节点的指针 置空的操作 在函数调用之后执行。
void new_contact(STU* ps);

// 函数名：delete_contact
// 函数参数：一个，ps 接收 通讯录首元结点
// 返回值：空
// 作用：释放链表中所有结点，避免内存泄露。
void delete_contact(STU* ps);

// 函数名：add_contact
// 函数参数：一个，ps 接收 通讯录首元结点
// 返回值：空
// 作用：新增一个学生，在链表尾部连上。若ps == 0，则新建一个结点。
void add_contact(STU*& ps);

// 函数名：insert_contact
// 函数参数：两个，ps 接收 通讯录首元结点；locat 表示 新节点插入后的位置，
//			 如果输入的是1，则在链头插入。
// 返回值：空
// 作用：将新结点插入通讯录中第locat个位置。若locat超过实际结点数量，则在尾部插入。
void insert_contact(STU*& ps, unsigned int locat);

// 函数名：del_student
// 函数参数：两个，ps 接收 通讯录首元结点；id 表示 要删除学生的学号。
// 返回值：int，1为删除成功，0为删除失败。
// 作用：根据输入的学号id删除指定结点，并保持删除结点后链表的链接性。
int del_student(STU*& ps, int id);

// 函数名：search_contact
// 函数参数：两个，ps 接收 通讯录首元结点；id 表示 要查找学生的学号。
// 返回值：STU*，不为0返回的是查找到学生的结点地址，0为查找失败。
// 作用：根据输入的学号id查找指定结点。
STU* search_contact(STU* ps, int id);

// 函数名：revise_contact
// 函数参数：一个，ps 接收 需要修改的学生信息结点
// 返回值：空
// 作用：传入修改学生结点的地址，打印其数据信息，打印修改菜单，选择需要改的信息选项进行修改
void revise_contact(STU* ps);

// 函数名：show_student
// 函数参数：一个，ps 接收 需要打印的学生信息结点
// 返回值：空
// 作用：打印传入的学生信息结点的数据信息
void show_student(STU* ps);

// 函数名：show_contact
// 函数参数：一个，ps 接收 通讯录首元结点
// 返回值：空
// 作用：打印所有通讯录的学生信息
void show_contact(STU* ps);

// 函数名：sort_contact
// 函数参数：两个，ps 接收 通讯录首元结点；end 记录 距离链头最近一个已经冒泡排序好的结点
// 返回值：空
// 作用：按学号冒泡递归排序链表
void sort_contact(STU* ps, STU* end);

// 函数名：readfile_contact
// 函数参数：一个，ps 接收 通讯录首元结点
// 返回值：空
// 作用：将contact.txt文件存储的数据读出，头插入已有通讯录中。
void readfile_contact(STU*& ps);

// 函数名：readfile_contact
// 函数参数：一个，ps 接收 通讯录首元结点
// 返回值：空
// 作用：将已有通讯录中所有学生信息写入到contact.txt文件中。
void whitefile_contact(STU* ps);
