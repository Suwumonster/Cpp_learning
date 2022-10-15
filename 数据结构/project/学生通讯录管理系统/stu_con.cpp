#define _CRT_SECURE_NO_WARNINGS 1

// ��Ŀ���ߣ�suwu ѧ�ţ�20212121013
// ��Ŀ����޸�ʱ�䣺 2022.10.14
// ������ɴ���Ŀ �޺�����

#include "stu_con.h"

// ��������new_contact
// ����������һ����ps ���� ͨѶ¼��Ԫ���
// ����ֵ����
// ���ã�����һ���µ�ͨѶ¼�������ɵ�ͨѶ¼��ʵ�����ǵ���ͨѶ¼�ͷź���delete_contact
//		 ��ÿ������ͷţ������ڴ�й¶��
// PS:��Ϊ��������ڸ���Ŀ���ò��࣬���Խ� ������Ԫ�ڵ��ָ�� �ÿյĲ��� �ں�������֮��ִ�С�
void new_contact(STU* ps)
{
	if (ps != 0)//�ж��Ƿ�Ϊ�գ������ͷſռ�
	{
		delete_contact(ps);
		ps = 0;
	}
}

// ��������delete_contact
// ����������һ����ps ���� ͨѶ¼��Ԫ���
// ����ֵ����
// ���ã��ͷ����������н�㣬�����ڴ�й¶��
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

// ��������add_contact
// ����������һ����ps ���� ͨѶ¼��Ԫ���
// ����ֵ����
// ���ã�����һ��ѧ����������β�����ϡ���ps == 0�����½�һ����㡣
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
	cout << "������ѧ��:";
	cin >> a->id;
	cout << "����������:";
	cin >> a->name;
	cout << "�������������(�ÿո���������):";
	cin >> a->birth.year >> a->birth.month >> a->birth.day;
	cout << "�������Ա�:";
	cin >> a->sex;
	cout << "�������ַ:";
	cin >> a->address;
	cout << "�������������:";
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

// ��������insert_contact
// ����������������ps ���� ͨѶ¼��Ԫ��㣻locat ��ʾ �½ڵ������λ�ã�
//			 ����������1��������ͷ���롣
// ����ֵ����
// ���ã����½�����ͨѶ¼�е�locat��λ�á���locat����ʵ�ʽ������������β�����롣
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

	//�½������
	cout << "������ѧ��:";
	cin >> a->id;
	cout << "����������:";
	cin >> a->name;
	cout << "�������������(�ÿո���������):";
	cin >> a->birth.year >> a->birth.month >> a->birth.day;
	cout << "�������Ա�:";
	cin >> a->sex;
	cout << "�������ַ:";
	cin >> a->address;
	cout << "�������������:";
	cin >> a->coordinate_x >> a->coordinate_y;
	int n = 2;

	//���� �ҵ�������λ��
	while (q != 0 && n < locat)
	{
		p = p->next;
		q = q->next;
		n++;
	}

	//������
	if (locat == 1)//����ͷ����
	{
		a->next = ps;
		ps = a;
	}
	else if(q == 0)//����β����
	{
		p->next = a;
		a->next = 0;
	}
	else//�������
	{
		p->next = a;
		a->next = q;
	}
}

// ��������del_student
// ����������������ps ���� ͨѶ¼��Ԫ��㣻id ��ʾ Ҫɾ��ѧ����ѧ�š�
// ����ֵ��int��1Ϊɾ���ɹ���0Ϊɾ��ʧ�ܡ�
// ���ã����������ѧ��idɾ��ָ����㣬������ɾ����������������ԡ�
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

	//ɾ�����
	if (p->id == id)//ɾ����һ���������
	{
		delete p;
		p = 0;
		ps = q;
		return 1;
	}
	while (q)//�������
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
	//�����޴�ѧ�ŵ����
	cout << "ͨѶ¼���޴�ѧ�ţ�" << endl;
	return 0;
}

// ��������num5_menu
// ������������
// ����ֵ����
// ���ã���ӡ�޸�ѧ����Ϣ�Ĳ˵�
void num5_menu()
{
	cout << "************************" << endl;
	cout << "****   1.�޸�ѧ��   ****" << endl;
	cout << "****   2.�޸�����   ****" << endl;
	cout << "****   3.�޸�����   ****" << endl;
	cout << "****   4.�޸��Ա�   ****" << endl;
	cout << "****   5.�޸ĵ�ַ   ****" << endl;
	cout << "****   6.�޸�����   ****" << endl;
	cout << "**** 0.�˻ص����˵� ****" << endl;
	cout << "************************" << endl;
}

// ��������search_contact
// ����������������ps ���� ͨѶ¼��Ԫ��㣻id ��ʾ Ҫ����ѧ����ѧ�š�
// ����ֵ��STU*����Ϊ0���ص��ǲ��ҵ�ѧ���Ľ���ַ��0Ϊ����ʧ�ܡ�
// ���ã����������ѧ��id����ָ����㡣
STU* search_contact(STU* ps, int id)
{
	if (ps == 0)
	{
		perror("search_contact::ָ��");
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

// ��������show_student
// ����������һ����ps ���� ��Ҫ��ӡ��ѧ����Ϣ���
// ����ֵ����
// ���ã���ӡ�����ѧ����Ϣ����������Ϣ
void show_student(STU* ps)
{
	cout << "��ѧ����Ϣ���£�" << endl;
	cout << std::left << setw(15) << "ѧ��" << "\t";
	cout << std::left << setw(15) << "����" << "\t";
	cout << std::left << setw(15) << "����" << "\t";
	cout << std::left << setw(15) << "�Ա�" << "\t";
	cout << std::left << setw(15) << "��ַ" << "\t";
	cout << std::left << setw(15) << "����" << endl;

	cout << std::left << setw(15) << ps->id << "\t";
	cout << std::left << setw(15) << ps->name << "\t";
	cout << std::left << setw(4) << ps->birth.year << " " << std::left << setw(2) << ps->birth.month << " " << std::left << setw(2) << ps->birth.day << "\t";
	cout << std::left << setw(15) << ps->sex << "\t";
	cout << std::left << setw(15) << ps->address << "\t";
	cout << std::left << setw(5) << ps->coordinate_x << " " << std::left << setw(5) << ps->coordinate_y << endl;
}

// ��������revise_contact
// ����������һ����ps ���� ��Ҫ�޸ĵ�ѧ����Ϣ���
// ����ֵ����
// ���ã������޸�ѧ�����ĵ�ַ����ӡ��������Ϣ����ӡ�޸Ĳ˵���ѡ����Ҫ�ĵ���Ϣѡ������޸�
void revise_contact(STU* ps)
{
	int input = 0;
	do
	{
		show_student(ps);
		num5_menu();
		cout << "����ѧ��Ϊ" << ps->id << "��ѧ���޸Ĳ˵�" << endl;
		cout << "�밴���ѡ��";
		cin >> input;
		switch (input)
		{
			case 1:
				cout << "�������޸�ѧ��" << endl;
				cin >> ps->id;
				cout << "�޸ĳɹ���" << endl;
				break;
			case 2:
				cout << "�������޸�����" << endl;
				cin >> ps->name;
				cout << "�޸ĳɹ���" << endl;
				break;
			case 3:
				cout << "�������޸�����" << endl;
				cin >> ps->birth.year >> ps->birth.month >> ps->birth.day;
				cout << "�޸ĳɹ���" << endl;
				break;
			case 4:
				cout << "�������޸��Ա�" << endl;
				cin >> ps->sex;
				cout << "�޸ĳɹ���" << endl;
				break;
			case 5:
				cout << "�������޸ĵ�ַ" << endl;
				cin >> ps->address;
				cout << "�޸ĳɹ���" << endl;
				break;
			case 6:
				cout << "�������޸�����" << endl;
				cin >> ps->coordinate_x >> ps->coordinate_y;
				cout << "�޸ĳɹ���" << endl;
				break;
			case 0:
				cout << "�˻����˵��ɹ���" << endl;
				break;
			default:
				cout << "����������������룡" << endl;
				break;
		}
	} while (input);
}

// ��������show_contact
// ����������һ����ps ���� ͨѶ¼��Ԫ���
// ����ֵ����
// ���ã���ӡ����ͨѶ¼��ѧ����Ϣ
void show_contact(STU* ps)
{
	cout << "����ѧ����Ϣ���£�" << endl;
	cout << std::left << setw(5) << " ";
	cout << std::left << setw(15) << "ѧ��" << "\t";
	cout << std::left << setw(15) << "����" << "\t";
	cout << std::left << setw(15) << "����" << "\t";
	cout << std::left << setw(15) << "�Ա�" << "\t";
	cout << std::left << setw(15) << "��ַ" << "\t";
	cout << std::left << setw(15) << "����" << endl;
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

// ��������sort_contact
// ����������������ps ���� ͨѶ¼��Ԫ��㣻end ��¼ ������ͷ���һ���Ѿ�ð������õĽ��
// ����ֵ����
// ���ã���ѧ��ð�ݵݹ���������
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

// ��������readfile_contact
// ����������һ����ps ���� ͨѶ¼��Ԫ���
// ����ֵ����
// ���ã���contact.txt�ļ��洢�����ݶ�����ͷ��������ͨѶ¼�С�
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

// ��������readfile_contact
// ����������һ����ps ���� ͨѶ¼��Ԫ���
// ����ֵ����
// ���ã�������ͨѶ¼������ѧ����Ϣд�뵽contact.txt�ļ��С�
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