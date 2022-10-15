#define _CRT_SECURE_NO_WARNINGS 1

// 项目作者：suwu 学号：20212121013
// 项目最后修改时间： 2022.10.14
// 单人完成此项目 无合作者

#include "stu_con.h"

// 函数名：new_contact
// 函数参数：一个，ps 接收 通讯录首元结点
// 返回值：空
// 作用：建立一个新的通讯录，舍弃旧的通讯录。实质上是调用通讯录释放函数delete_contact
//		 将每个结点释放，避免内存泄露。
// PS:因为这个函数在该项目调用不多，所以将 保存首元节点的指针 置空的操作 在函数调用之后执行。
void new_contact(STU* ps)
{
	if (ps != 0)//判断是否为空，不空释放空间
	{
		delete_contact(ps);
		ps = 0;
	}
}

// 函数名：delete_contact
// 函数参数：一个，ps 接收 通讯录首元结点
// 返回值：空
// 作用：释放链表中所有结点，避免内存泄露。
void delete_contact(STU* ps)
{
	STU* p;
	while (ps)
	{
		p = ps->next;
		delete ps;
		ps = p;
	}
}

// 函数名：add_contact
// 函数参数：一个，ps 接收 通讯录首元结点
// 返回值：空
// 作用：新增一个学生，在链表尾部连上。若ps == 0，则新建一个结点。
void add_contact(STU*& ps)
{
	STU* tail = 0;
	STU* a = 0;
	tail = ps;
	while (tail != 0 && tail->next != 0)
	{
		tail = tail->next;
	}
	a = new STU;
	cout << "请输入学号:";
	cin >> a->id;
	cout << "请输入姓名:";
	cin >> a->name;
	cout << "请输入出生日期(用空格间隔年月日):";
	cin >> a->birth.year >> a->birth.month >> a->birth.day;
	cout << "请输入性别:";
	cin >> a->sex;
	cout << "请输入地址:";
	cin >> a->address;
	cout << "请输入横纵坐标:";
	cin >> a->coordinate_x >> a->coordinate_y;
	a->next = 0;
	if (tail == 0)
	{
		ps = a;
	}
	else
	{
		tail->next = a;
	}
}

// 函数名：insert_contact
// 函数参数：两个，ps 接收 通讯录首元结点；locat 表示 新节点插入后的位置，
//			 如果输入的是1，则在链头插入。
// 返回值：空
// 作用：将新结点插入通讯录中第locat个位置。若locat超过实际结点数量，则在尾部插入。
void insert_contact(STU*& ps, unsigned int locat)
{
	if (ps == 0)
	{
		add_contact(ps);
		return;
	}
	if (locat == 0)
	{
		cout << "locat can't be 0!" << endl;
		return;
	}
	STU* p, *q;
	p = ps;
	q = p->next;
	STU* a;
	a = new STU;

	//新结点输入
	cout << "请输入学号:";
	cin >> a->id;
	cout << "请输入姓名:";
	cin >> a->name;
	cout << "请输入出生日期(用空格间隔年月日):";
	cin >> a->birth.year >> a->birth.month >> a->birth.day;
	cout << "请输入性别:";
	cin >> a->sex;
	cout << "请输入地址:";
	cin >> a->address;
	cout << "请输入横纵坐标:";
	cin >> a->coordinate_x >> a->coordinate_y;
	int n = 2;

	//遍历 找到插入结点位置
	while (q != 0 && n < locat)
	{
		p = p->next;
		q = q->next;
		n++;
	}

	//结点插入
	if (locat == 1)//在链头插入
	{
		a->next = ps;
		ps = a;
	}
	else if(q == 0)//在链尾插入
	{
		p->next = a;
		a->next = 0;
	}
	else//其他情况
	{
		p->next = a;
		a->next = q;
	}
}

// 函数名：del_student
// 函数参数：两个，ps 接收 通讯录首元结点；id 表示 要删除学生的学号。
// 返回值：int，1为删除成功，0为删除失败。
// 作用：根据输入的学号id删除指定结点，并保持删除结点后链表的链接性。
int del_student(STU*& ps, int id)
{
	if (ps == 0)
	{
		perror("ps");
		return 0;
	}
	STU* p, *q;
	p = ps;
	q = ps->next;

	//删除结点
	if (p->id == id)//删除第一个结点的情况
	{
		delete p;
		p = 0;
		ps = q;
		return 1;
	}
	while (q)//其他情况
	{
		if (q->id == id)
		{
			p->next = q->next;
			delete q;
			q = 0;
			return 1;
		}
		p = p->next;
		q = q->next;
	}
	//表中无此学号的情况
	cout << "通讯录中无此学号！" << endl;
	return 0;
}

// 函数名：num5_menu
// 函数参数：无
// 返回值：空
// 作用：打印修改学生信息的菜单
void num5_menu()
{
	cout << "************************" << endl;
	cout << "****   1.修改学号   ****" << endl;
	cout << "****   2.修改名字   ****" << endl;
	cout << "****   3.修改生日   ****" << endl;
	cout << "****   4.修改性别   ****" << endl;
	cout << "****   5.修改地址   ****" << endl;
	cout << "****   6.修改坐标   ****" << endl;
	cout << "**** 0.退回到主菜单 ****" << endl;
	cout << "************************" << endl;
}

// 函数名：search_contact
// 函数参数：两个，ps 接收 通讯录首元结点；id 表示 要查找学生的学号。
// 返回值：STU*，不为0返回的是查找到学生的结点地址，0为查找失败。
// 作用：根据输入的学号id查找指定结点。
STU* search_contact(STU* ps, int id)
{
	if (ps == 0)
	{
		perror("search_contact::指针");
		return 0;
	}
	STU* p = ps;
	while (p)
	{
		if (p->id == id)
		{
			return p;
		}
		p = p->next;
	}
	return 0;
}

// 函数名：show_student
// 函数参数：一个，ps 接收 需要打印的学生信息结点
// 返回值：空
// 作用：打印传入的学生信息结点的数据信息
void show_student(STU* ps)
{
	cout << "该学生信息如下：" << endl;
	cout << std::left << setw(15) << "学号" << "\t";
	cout << std::left << setw(15) << "姓名" << "\t";
	cout << std::left << setw(15) << "生日" << "\t";
	cout << std::left << setw(15) << "性别" << "\t";
	cout << std::left << setw(15) << "地址" << "\t";
	cout << std::left << setw(15) << "坐标" << endl;

	cout << std::left << setw(15) << ps->id << "\t";
	cout << std::left << setw(15) << ps->name << "\t";
	cout << std::left << setw(4) << ps->birth.year << " " << std::left << setw(2) << ps->birth.month << " " << std::left << setw(2) << ps->birth.day << "\t";
	cout << std::left << setw(15) << ps->sex << "\t";
	cout << std::left << setw(15) << ps->address << "\t";
	cout << std::left << setw(5) << ps->coordinate_x << " " << std::left << setw(5) << ps->coordinate_y << endl;
}

// 函数名：revise_contact
// 函数参数：一个，ps 接收 需要修改的学生信息结点
// 返回值：空
// 作用：传入修改学生结点的地址，打印其数据信息，打印修改菜单，选择需要改的信息选项进行修改
void revise_contact(STU* ps)
{
	int input = 0;
	do
	{
		show_student(ps);
		num5_menu();
		cout << "这是学号为" << ps->id << "的学生修改菜单" << endl;
		cout << "请按序号选择：";
		cin >> input;
		switch (input)
		{
			case 1:
				cout << "你正在修改学号" << endl;
				cin >> ps->id;
				cout << "修改成功！" << endl;
				break;
			case 2:
				cout << "你正在修改姓名" << endl;
				cin >> ps->name;
				cout << "修改成功！" << endl;
				break;
			case 3:
				cout << "你正在修改生日" << endl;
				cin >> ps->birth.year >> ps->birth.month >> ps->birth.day;
				cout << "修改成功！" << endl;
				break;
			case 4:
				cout << "你正在修改性别" << endl;
				cin >> ps->sex;
				cout << "修改成功！" << endl;
				break;
			case 5:
				cout << "你正在修改地址" << endl;
				cin >> ps->address;
				cout << "修改成功！" << endl;
				break;
			case 6:
				cout << "你正在修改坐标" << endl;
				cin >> ps->coordinate_x >> ps->coordinate_y;
				cout << "修改成功！" << endl;
				break;
			case 0:
				cout << "退回主菜单成功！" << endl;
				break;
			default:
				cout << "输入错误请重新输入！" << endl;
				break;
		}
	} while (input);
}

// 函数名：show_contact
// 函数参数：一个，ps 接收 通讯录首元结点
// 返回值：空
// 作用：打印所有通讯录的学生信息
void show_contact(STU* ps)
{
	cout << "所有学生信息如下：" << endl;
	cout << std::left << setw(5) << " ";
	cout << std::left << setw(15) << "学号" << "\t";
	cout << std::left << setw(15) << "姓名" << "\t";
	cout << std::left << setw(15) << "生日" << "\t";
	cout << std::left << setw(15) << "性别" << "\t";
	cout << std::left << setw(15) << "地址" << "\t";
	cout << std::left << setw(15) << "坐标" << endl;
	int n = 1;
	while (ps)
	{
		cout << std::left << setw(5) << n++ ;
		cout << std::left << setw(15) << ps->id << "\t";
		cout << std::left << setw(15) << ps->name << "\t";
		cout << std::left << setw(4) << ps->birth.year << " " << std::left << setw(2) << ps->birth.month << " " << std::left << setw(2) << ps->birth.day << "\t";
		cout << std::left << setw(15) << ps->sex << "\t";
		cout << std::left << setw(15) << ps->address << "\t";
		cout << std::left << setw(5) << ps->coordinate_x << " " << std::left << setw(5) << ps->coordinate_y << endl;
		ps = ps->next;
	}
}

// 函数名：sort_contact
// 函数参数：两个，ps 接收 通讯录首元结点；end 记录 距离链头最近一个已经冒泡排序好的结点
// 返回值：空
// 作用：按学号冒泡递归排序链表
void sort_contact(STU* ps, STU* end)
{
	if (ps == end)
	{
		return;
	}
	STU* p = ps;
	STU* q = ps->next;
	int id;
	char name[20];
	DATE birth;
	char sex[20];
	char address[20];
	float coordinate_x;
	float coordinate_y;
	while (q != end)
	{
		if (p->id > q->id)
		{
			id = p->id;
			p->id = q->id;
			q->id = id;

			strcpy(name, p->name);
			strcpy(p->name, q->name);
			strcpy(q->name, name);

			birth = p->birth;
			p->birth = q->birth;
			q->birth = birth;

			strcpy(sex, p->sex);
			strcpy(p->sex, q->sex);
			strcpy(q->sex, sex);

			strcpy(address, p->address);
			strcpy(p->address, q->address);
			strcpy(q->address, address);

			coordinate_x = p->coordinate_x;
			p->coordinate_x = q->coordinate_x;
			q->coordinate_x = coordinate_x;
			coordinate_y = p->coordinate_y;
			p->coordinate_y = q->coordinate_y;
			q->coordinate_y = coordinate_y;
		}
		p = p->next;
		q = q->next;
	}
	end = p;
	sort_contact(ps, end);
}

// 函数名：readfile_contact
// 函数参数：一个，ps 接收 通讯录首元结点
// 返回值：空
// 作用：将contact.txt文件存储的数据读出，头插入已有通讯录中。
void readfile_contact(STU*& ps)
{
	ifstream file("contact.txt", ios::in | ios::binary);
	if (!file.is_open())
	{
		perror("contact.txt");
		return;
	}
	STU tmp;
	STU* a = 0;
	while (file.read((char*)&tmp, sizeof(tmp)))
	{
		a = new STU;
		*a = tmp;
		a->next = ps;
		ps = a;
	}

	file.close();
}

// 函数名：readfile_contact
// 函数参数：一个，ps 接收 通讯录首元结点
// 返回值：空
// 作用：将已有通讯录中所有学生信息写入到contact.txt文件中。
void whitefile_contact(STU* ps)
{
	ofstream file("contact.txt", ios::out | ios::binary);
	if (!file.is_open())
	{
		perror("contact.txt");
		return;
	}

	while ( ps != 0 && file.write((const char*)ps, sizeof(STU)))
	{
		ps = ps->next;
	}

	file.close();
}