#include"menu.h"
#include"book.h"
#include"mgrfun.h"
#include"readerfun.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
void menu::display_1() {
	while (true)
	{
		system("cls");//�����Ļ����
		cout << "***************************" << endl;
		cout << "��ӭ����ͼ�����ϵͳ��" << endl;
		cout << "��ѡ���Ժ�����ݵ�¼��" << endl;
		cout << "1.����Ա" << endl;
		cout << "2.����" << endl;
		cout << "3.�˳�" << endl;
		cout << "***************************" << endl;
		int t;
		do {
			cin >> t;
			switch (t)
			{
			case 1:display_2(); break;
			case 2:display_3(); break;
			case 3:
				cout << "��л����ʹ�ã�" << endl;
				system("pause");
				exit(0);
			default:
				cout << "�����������������" << endl;
			}
		} while (t != 1 && t != 2 && t != 3);//��ֹ�������
	}
}
void menu::display_2()
{

	while (true)
	{
		system("cls");
		cout << "***************************" << endl;
		cout << "��ӭ����ͼ�����ϵͳ��" << endl;
		cout << "1.��½�˺�" << endl;
		cout << "2.�޸Ĺ���Ա��Ϣ" << endl;
		cout << "3.�˳�" << endl;
		cout << "***************************" << endl;
		int t;
		do {
			cin >> t;
			switch (t)
			{
				mangerfun a1;//�򿪹����߹�����
			case 1:a1.getManage(); break;//����getManage()����
			case 2:a1.reviseInformation(); break;//����reviseInformation()����
			case 3:
				cout << "��л����ʹ�ã�" << endl;
				system("pause");
				exit(0);
			default:
				cout << "�������,����������" << endl;
			}
		} while (t != 1 && t != 2 && t != 3);
	}
}
void menu::display_3()
{
	while (true)
	{
		system("cls");//�����Ļ����
		cout << "***************************" << endl;
		cout << "��ӭ����ͼ�����ϵͳ��" << endl;
		cout << "1.��½�˺�" << endl;
		cout << "2.�޸Ķ�����Ϣ" << endl;
		cout << "3.�˳�" << endl;
		cout << "***************************" << endl;
		int t;
		do {
			cin >> t;
			switch (t)
			{
				readerfun b1;//�򿪶��߹�����
			case 1:b1.getStudent(); break;
			case 2:b1.changeCode(); break;
			case 3:
				cout << "��л����ʹ�ã�" << endl;//�˳�
				system("pause");
				exit(0);
			default:
				cout << "�������,����������" << endl;//������ʾ
			}
		} while (t !=1 &&t!=2&&t!=3);
	}

}