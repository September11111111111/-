#include"readerfun.h"
#include"reader.h"

void readerfun::search()
{
	reader reader3;//ʵ��������
	reader3.search();//����reader���е�search()����
	cout << "�Ƿ������ѯ��1���ǣ�2����" << endl;//ѭ���ж�
	int  a;
	do {
		cin >> a;
		if (a == 1) {
			readerfun::search();
		}
		else if (a == 2) {
			return ;
		}
		else
		{
			cout << "����������������룡" << endl;
		}
	} while (a != 1 && a != 2);
}
void readerfun::borrowBook()
{
	reader reader4;//ʵ��������
	for(int a=1;a!=2;){
		reader4.borrowBook();//����reader���е�borrowBook()����
		cout << "�Ƿ�������飨1���ǣ�2����" << endl;//ѭ���ж�
		do {
			cin >> a;
			if (a == 1)
			{
				reader4.borrowBook();
			}
			else if (a == 2) return;
			else
			{
				cout << "����������������룡" << endl;
			}
		} while (a != 1 && a != 2);
		}
}
void readerfun::changeCode()
{
	reader reader6;//ʵ��������
	for (int a = 1; a != 2;)//ѭ���޸�����
	{
		reader6.changeCode();//����reader���е�changeCode()����
		cout << "�Ƿ�����޸ģ�1���ǣ�2����" << endl;//ѭ���ж�
		do {
			cin >> a;
			if (a == 1)
			{
				reader6.changeCode();
			}
			else if (a == 2)
			{
				return;
			}
			else
			{
				cout << "����������������룡" << endl;//���������ʾ
			}
		} while (a != 1 && a != 2);
	}
}
void readerfun::returnBook() {
	reader reader5;//ʵ��������
	for (int temp = 1; temp;)//ѭ������
	{
		reader5.returnBook();//����reader���е�returnBook()����
		cout << "�Ƿ�������飨1���ǣ�2����" << endl;//ѭ���ж�
		int a;//�������
		cin >> a;
		do {
			if (a == 1) temp = 1;
			else if (a == 2) temp = 0;
			else
			{
				cout << "����������������룡" << endl;
				temp = 1;//���������ʾ
			}
		} while (a != 1 && a != 2);
	}
}

void readerfun::getStudent()//���ڵ�¼�˺�
{
	reader reader5;
	int max_attempts = 3; // ����Դ���
	for (int temp = 1, attempt = 0; temp && attempt < max_attempts; attempt++)
	{
		int a;//����getInformation()�ķ���ֵ
		a = reader5.getInformation();//����reader���е�getInformation()����
		if (a == 1)//��½�ɹ�
		{
			while (true)
			{
				system("cls");//�����Ļ����
				cout << "***************************" << endl;
				cout << "��ӭ����ͼ�����ϵͳ��" << endl;
				cout << "��ѡ����Ӧ���ܣ�" << endl;
				cout << "1.��ѯ�鼮��Ϣ" << endl;
				cout << "2.�����鼮" << endl;
				cout << "3.�����鼮" << endl;
				cout << "4.�˳�" << endl;
				cout << "***************************" << endl;
				int t;
				int temp = 0;
				do {
					if (temp) {
						cout << "����������������룡";
					}
					cin >> t;
					temp++;
				} while (t != 1 && t != 2 && t != 3 && t != 4);
				switch (t)
				{
				case 1:search(); break;//����search()����
				case 2:borrowBook(); break;//����borrowBook()����
				case 3:returnBook(); break;//����returnBook()����
				case 4:
					cout << "��л����ʹ�ã�" << endl;//�˳�
					system("pause");
					exit(0);
				}
			}
		}
		else
		{
			if (attempt < max_attempts - 1)
			{
				cout << "�Ƿ�������루1���ǣ�2����" << endl;//ѭ���ж�
				int a;//�������
				cin >> a;
				do {
					if (a == 1) temp = 1;
					else if (a == 2) temp = 0;
					else
					{
						cout << "����������������룡" << endl;
						temp = 1;//���������ʾ
					}
				} while (a != 1 && a != 2);
			}
			else
			{
				cout << "���Ѿ����������Σ���¼ʧ��!" << endl;
				temp = 0;
			}
		}
	}
}
