#include"mgrfun.h"
#include"manager.h"
void mangerfun::addbook()
{
	manage manage1;//ʵ��������
	for (int temp = 1; temp;)//ѭ������鼮
	{
		manage1.add();//����manage���е�add��������
		cout << "�Ƿ��������鼮��1���ǣ�2����" << endl;//�ж��Ƿ�ѭ��
		int a;//�������
		do {
			cin >> a;
			if (a == 1) temp = 1;
			else if (a == 2) temp = 0;
			else
			{
				cout << "�������!����������" << endl; temp = 1;//���������ʾ
			}
		} while (a != 1 && a != 2);
	}
}
void mangerfun::deletebook() {
	manage manage6;//ʵ��������
	for (int temp = 1; temp;)//ѭ��ɾ���鼮
	{
		manage6.deleteBook();//����manage���е�deleteBook()����
		cout << "�Ƿ����ɾ���鼮��1���ǣ�2����" << endl;//�ж��Ƿ�ѭ��
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
void mangerfun::changebook() {
	manage manage2;//ʵ��������
	for (int temp = 1; temp;)//ѭ���޸��鼮
	{
		manage2.revise();//����manage����revise��������
		cout << "�Ƿ�����޸ģ�1���ǣ�2����" << endl;//ѭ���ж�
		int a;//�������
		do {
			cin >> a;
			if (a == 1) temp = 1;
			else if (a == 2) temp = 0;
			else
			{
				cout << "����������������룡" << endl;
			}
		} while (a != 1 && a != 2);
	}
}
void mangerfun::addReader()
{
	manage manage3;//ʵ��������
	for (int a = 1; a != 2;)//ѭ������
	{
		manage3.addReader();//����manage����addReader��������
		cout << "�Ƿ������Ӷ��ߣ�1���ǣ�2����" << endl;//ѭ���ж�
		do {
			cin >> a;
			if (a == 1)
			{
				manage3.addReader();
			}
			else if (a == 2) {
				return;
			}
			else
			{
				cout << "����������������룡" << endl;
			}
		} while (a != 1 && a != 2);
	}
}
void mangerfun::deleteReader()
{
	manage manage7;//ʵ��������
	for (int temp = 1; temp;)//ѭ��ɾ��
	{
		manage7.deleteReader();//����manage����deleteReader��������
		cout << "�Ƿ����ɾ�����ߣ�1���ǣ�2����" << endl;//ѭ���ж�
		int a;//�������
		do {
			cin >> a;
			if (a == 1) temp = 1;
			else if (a == 2) temp = 0;
			else
			{
				cout << "����������������룡" << endl;
			}
		} while (a != 1 && a != 2);
	}
}
void mangerfun::getManage()
{
	manage manage4;//ʵ��������
	int max_attempts = 3;
	for (int temp = 1, attempt = 0; temp && attempt < max_attempts; attempt++)//ѭ����½
	{
		int b;//����getManage()�ķ���ֵ
		b = manage4.getManage();//����manage���е�getManage()����
		if (b == 1)//��½�ɹ�
		{
			while (true)
			{
				system("cls");//�����Ļ����
				cout << "***************************" << endl;
				cout << "��ӭ����ͼ�����ϵͳ��" << endl;
				cout << "��ѡ����Ӧ���ܣ�" << endl;
				cout << "1.���Ӷ���" << endl;
				cout << "2.ɾ������" << endl;
				cout << "3.�����鼮��Ϣ" << endl;
				cout << "4.ɾ���鼮��Ϣ" << endl;
				cout << "5.�޸��鼮��Ϣ" << endl;
				cout << "6.�˳�" << endl;
				int t;
				int temp = 0;
				do {
					if (temp) {
						cout << "����������������룡";
					}
					cin >> t;
					temp++;
				} while (t != 1 && t != 2 && t != 3 && t != 4 && t != 5 && t != 6);
				switch (t)
				{
				case 1:addReader(); break;//����addReader()����
				case 2:deleteReader(); break;//����deleteReader()����
				case 3:addbook(); break;//����addbook()����
				case 4:deletebook(); break;//����deletebook()����
				case 5:changebook(); break;//����changebook()����
				case 6:
					cout << "��л����ʹ�ã�" << endl;//�˳�
					system("pause");
					exit(0);
				}

			}

		}

		else//��¼ʧ���ж��Ƿ��ٴε�½
		{
			if (attempt < max_attempts - 1)
			{
				cout << "�Ƿ������½��1���ǣ�2����" << endl;//ѭ���ж�
				int  a;//�������
				do {
					cin >> a;
					if (a == 1)
					{
						temp = 1;

					}
					else if (a == 2) temp = 0;
					else
					{
						cout << "�������!" << endl; //���������ʾ
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
void mangerfun::reviseInformation()
{
	manage manage5;//ʵ��������
	for (int temp = 1; temp;)//ѭ���޸�
	{
		manage5.reviseInformation();//����manage���е�reviseInformation()����
		cout << "�Ƿ�����޸ģ�1���ǣ�2����" << endl;//ѭ���ж�
		int  a;//�������
		do {
			cin >> a;
			if (a == 1) temp = 1;
			else if (a == 2) temp = 0;
			else
			{
				cout << "�����������������" << endl; 
			}
		} while (a != 1 && a != 2);
	}
}