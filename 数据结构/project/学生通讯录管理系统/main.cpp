#define _CRT_SECURE_NO_WARNINGS 1

// ��Ŀ���ߣ�suwu ѧ�ţ�20212121013
// ��Ŀ����޸�ʱ�䣺 2022.10.14
// ������ɴ���Ŀ �޺�����

#include "stu_con.h"

// ��������menu
// ������������
// ����ֵ����
// ���ã���ӡ�ܲ˵�
void menu()
{
	cout << "*************************************************************" << endl;
	cout << "****                 ѧ��ͨѶ¼����ϵͳ                  ****" << endl;
	cout << "****     1.�½�һ��ͨѶ¼         2.����ѧ��             ****" << endl;
	cout << "****     3.��λ�úŲ���ѧ��       4.��ѧ��ɾ��ѧ��       ****" << endl;
	cout << "****     5.��ѧ���޸�ѧ����Ϣ     6.��ѧ��������ʾѧ��   ****" << endl;
	cout << "****     7.��ѧ�Ų���ѧ��         8.��ʾȫ��ѧ����Ϣ     ****" << endl;
	cout << "****     9.��ȡ�ļ���ѧ����Ϣ     10.��ѧ����Ϣд���ļ�  ****" << endl;
	cout << "****                       11.�˳�                       ****" << endl;
	cout << "*************************************************************" << endl;
}


int main()
{
	int input = 0;//�����������˵�ѡ��
	int id = 0;//��������ѧ��
	STU* head = 0;//ͨѶ¼��Ԫ�ڵ�
	STU* tmp = 0;//���� ���ҵ���ѧ�����
	unsigned int locat = 0;
	do
	{
		menu();
		cout << "�밴���ѡ��";
		cin >> input;
		switch (input)
		{
			case 1://�½�һ��ͨѶ¼
				new_contact(head);
				head = 0;
				cout << "�½��ɹ���" << endl;
				break;

			case 2://����ѧ��
				add_contact(head);
				cout << "���ӳɹ���" << endl;
				break;

			case 3://��λ�úŲ���ѧ��
				cout << "������Ҫ�����λ�ú�:";
				cin >> locat;
				insert_contact(head, locat);
				cout << "����ɹ���" << endl;
				break;

			case 4://��ѧ��ɾ��ѧ��
				id = 0;
				cout << "����Ҫɾ��ѧ����ѧ��:";
				cin >> id;
				if (del_student(head, id))
				{
					cout << "ɾ���ɹ���" << endl;
				}
				else
				{
					cout << "ɾ��ʧ�ܣ�" << endl;
				}
				break;

			case 5://��ѧ���޸�ѧ����Ϣ
				id = 0;
				cout << "����Ҫ�޸ĵ�ѧ����ѧ��:";
				cin >> id;
				tmp = search_contact(head, id);
				if (tmp != 0)
				{
					revise_contact(tmp);
				}
				else
				{
					cout << "�޸�ʧ�ܣ�ͨѶ¼�޴��ˣ�" << endl;
				}
				break;

			case 6://��ѧ��������ʾ����ѧ��
				sort_contact(head, 0);
				show_contact(head);
				break;

			case 7://��ѧ�Ų���ѧ��
				id = 0;
				cout << "����Ҫ���ҵ�ѧ����ѧ��:";
				cin >> id;
				tmp = search_contact(head, id);
				if (tmp != 0)
				{
					cout << "���ҳɹ���" << endl;
					show_student(tmp);
				}
				else
				{
					cout << "����ʧ�ܣ��б��޴��ˣ�" << endl;
				}
				break;

			case 8://��ʾȫ��ѧ����Ϣ
				show_contact(head);
				break;

			case 9://��ȡ�ļ���ѧ����Ϣ
				readfile_contact(head);
				break;

			case 10://��ѧ����Ϣд���ļ�
				whitefile_contact(head);
				break;

			case 0://�˳�����
				whitefile_contact(head);
				cout << "�˳��ɹ���" << endl;
				break;

			default:
				cout << "����������������룡" << endl;
				break;
		}
	} while (input != 11);
	return 0;
}