#pragma once

// ��Ŀ���ߣ�suwu ѧ�ţ�20212121013
// ��Ŀ����޸�ʱ�䣺 2022.10.14
// ������ɴ���Ŀ �޺�����

#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;


typedef struct DATE//����������
{
	int year;
	int month;
	int day;
}DATE;


typedef struct STU//ѧ����Ϣ���
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

// ��������new_contact
// ����������һ����ps ���� ͨѶ¼��Ԫ���
// ����ֵ����
// ���ã�����һ���µ�ͨѶ¼�������ɵ�ͨѶ¼��ʵ�����ǵ���ͨѶ¼�ͷź���delete_contact
//		 ��ÿ������ͷţ������ڴ�й¶��
// PS:��Ϊ��������ڸ���Ŀ���ò��࣬���Խ� ������Ԫ�ڵ��ָ�� �ÿյĲ��� �ں�������֮��ִ�С�
void new_contact(STU* ps);

// ��������delete_contact
// ����������һ����ps ���� ͨѶ¼��Ԫ���
// ����ֵ����
// ���ã��ͷ����������н�㣬�����ڴ�й¶��
void delete_contact(STU* ps);

// ��������add_contact
// ����������һ����ps ���� ͨѶ¼��Ԫ���
// ����ֵ����
// ���ã�����һ��ѧ����������β�����ϡ���ps == 0�����½�һ����㡣
void add_contact(STU*& ps);

// ��������insert_contact
// ����������������ps ���� ͨѶ¼��Ԫ��㣻locat ��ʾ �½ڵ������λ�ã�
//			 ����������1��������ͷ���롣
// ����ֵ����
// ���ã����½�����ͨѶ¼�е�locat��λ�á���locat����ʵ�ʽ������������β�����롣
void insert_contact(STU*& ps, unsigned int locat);

// ��������del_student
// ����������������ps ���� ͨѶ¼��Ԫ��㣻id ��ʾ Ҫɾ��ѧ����ѧ�š�
// ����ֵ��int��1Ϊɾ���ɹ���0Ϊɾ��ʧ�ܡ�
// ���ã����������ѧ��idɾ��ָ����㣬������ɾ����������������ԡ�
int del_student(STU*& ps, int id);

// ��������search_contact
// ����������������ps ���� ͨѶ¼��Ԫ��㣻id ��ʾ Ҫ����ѧ����ѧ�š�
// ����ֵ��STU*����Ϊ0���ص��ǲ��ҵ�ѧ���Ľ���ַ��0Ϊ����ʧ�ܡ�
// ���ã����������ѧ��id����ָ����㡣
STU* search_contact(STU* ps, int id);

// ��������revise_contact
// ����������һ����ps ���� ��Ҫ�޸ĵ�ѧ����Ϣ���
// ����ֵ����
// ���ã������޸�ѧ�����ĵ�ַ����ӡ��������Ϣ����ӡ�޸Ĳ˵���ѡ����Ҫ�ĵ���Ϣѡ������޸�
void revise_contact(STU* ps);

// ��������show_student
// ����������һ����ps ���� ��Ҫ��ӡ��ѧ����Ϣ���
// ����ֵ����
// ���ã���ӡ�����ѧ����Ϣ����������Ϣ
void show_student(STU* ps);

// ��������show_contact
// ����������һ����ps ���� ͨѶ¼��Ԫ���
// ����ֵ����
// ���ã���ӡ����ͨѶ¼��ѧ����Ϣ
void show_contact(STU* ps);

// ��������sort_contact
// ����������������ps ���� ͨѶ¼��Ԫ��㣻end ��¼ ������ͷ���һ���Ѿ�ð������õĽ��
// ����ֵ����
// ���ã���ѧ��ð�ݵݹ���������
void sort_contact(STU* ps, STU* end);

// ��������readfile_contact
// ����������һ����ps ���� ͨѶ¼��Ԫ���
// ����ֵ����
// ���ã���contact.txt�ļ��洢�����ݶ�����ͷ��������ͨѶ¼�С�
void readfile_contact(STU*& ps);

// ��������readfile_contact
// ����������һ����ps ���� ͨѶ¼��Ԫ���
// ����ֵ����
// ���ã�������ͨѶ¼������ѧ����Ϣд�뵽contact.txt�ļ��С�
void whitefile_contact(STU* ps);
