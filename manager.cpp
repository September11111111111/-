#include "manager.h"
#include"book.h"
#include"handle.h"
manage::manage()//��������
{

}

bool manage::getManage()//��¼����
{
	cout << "��ӭ��½ͼ�����ϵͳ��" << endl;
	string a, b;
	cout << "�������˺ţ�" << endl;
	cin >> a;
	cout << "���������룺" << endl;
	cin >> b;
	string n, c;
	ifstream in("manage.txt");//���ļ�
	int i = 0;//��ǩ���ж��˺ŵĴ������
	do
	{
		if (in.eof())//�ļ�β�ͽ���
			break;

		string s;
		getline(in, s);//����ÿһ��
		istringstream sin(s);
		sin >> n >> c;
		if ((a == n) && (c == b))//�ж��Ƿ����
		{
			i = 1;
			return 1;
			cout << "��½�ɹ���" << endl;
			break;

		}
	} while (!in.eof());//�ж��Ƿ��ļ�β

	if (i == 0)//δ�ҵ��˺�
		cout << "���벻��ȷ��" << endl;
	return 0;
	in.close();//�ر��ļ�
}

void manage::reviseInformation()//�޸���Ϣ����
{
	int t = 0;//��ǩ���Ƿ���ڸ��˺�
	string a, b, c, d;
	cout << "�����������Ϣ��" << endl;
	cout << "�˺ţ�" << endl;
	cin >> c;
	cout << "���룺" << endl;
	cin >> d;
	ifstream in("manage.txt");//���ļ�
	string s1;
	while (getline(in, s1))//��������
	{
		istringstream sin(s1);//����sin��
		sin >> a >> b;
		
		if ((a == c) && (b == d))//���ڸ��˺�
		{
			cout << "���˺Ŵ���" << endl;
			t = 1;
			string m, p;
			cout << "�������޸ĺ����Ϣ:" << endl;
			cout << "���˺ţ�" << endl;
			cin >> m;
			cout << "�����룺" << endl;
			cin >> p;
			handle hero;
			hero.changemanageinformation(c, m, p);
			cout << "�޸ĳɹ�" << endl;
			return;
		}
		
	}
	in.close();//�ر��ļ�
	cout << "***************************" << endl;
	cout << "�˺Ų����ڣ�����Ϊ���½�һ���˺�" << endl;
	cout << "***************************" << endl;
	ofstream out("manage.txt", ios::app);//���ļ�
	out << c << " " << d << endl;
	cout << "�����˺����" << endl;
	out.close();

}

void manage::add()//��������鼮����
{
	book book1;//ʵ��������
	ofstream fileout("store.txt", ios::app);//���ļ�
	if (!fileout)
	{
		cout << "���ܴ��ļ���" << "store.txt" << endl;
	}
	else
	{
		cout << "�������鱾������Ϣ��" << endl;
		book1.readBookInformation();//������Ϣ
		fileout << book1.getName() << " " << book1.getbookAuthor() << " " << book1.getbookISBN() << " " << book1.gettype()
			<< " " << book1.getbookPress() << " " << book1.getbookStatue() << endl;//д����Ϣ
	}
	fileout.close();//�ر��ļ�

}

void manage::revise()//�����޸��鼮��Ϣ����
{
	book book1;//ʵ��������
	ifstream filein("store.txt");//���ļ�
	if (!filein)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
	}
	else
	{
		cout << "�������޸��鼮�ĵ�������" << endl;
		int n = 0;//��ǩ���Ƿ����Ȿ��
		string t;//��������
		cin >> t;
		do
		{
			int v;//�������
			string x, y, z, u, w;
			string s;
			getline(filein, s);//����ÿһ��
			istringstream sin(s);
			sin >> x;//��s�е�һ���ַ�����x

			if (t == x)//�ж��Ƿ�Ϊ�޸ĵĵط�
			{
				n = 1;
				sin >> y >> z >> u >> w >> v;//��һ���ַ�������
				book1.setName(x);//�趨����
				book1.setAuthor(y);//�趨����
				book1.setISBN(z);//�趨ISBN��
				book1.settype(u);//�趨����
				book1.setPress(w);//�趨������
				book1.setStatue(v);//�趨״̬
				cout << "ԭ�鼮��ϢΪ:" << endl;
				book1.printBookInformation();//���

				cout << "�������޸ĺ���鼮��Ϣ��" << endl;
				book1.readBookInformation();//���¶���
				handle hero;
				hero.revisebookinformation(x, book1.getName(), book1.getbookAuthor(), book1.getbookISBN(), book1.gettype(), book1.getbookPress(), book1.getbookStatue());
				cout << "�޸����" << endl;
				break;
			}
		} while (!filein.eof());//�ж��Ƿ��ļ�β
		if (n == 0) {
			cout << "δ�ҵ�Ҫ�޸ĵ��鼮��" << endl;
		}
		filein.close();
	}
}


void manage::deleteBook()
{
	string  m;
	cout << "������ɾ���鼮�����֣�" << endl;
	cin >> m;

	ifstream filein("store.txt");//���ļ�
	bool i = 0;//��ǩ���ж��˺ŵĴ������
	do
	{
		if (filein.eof())//�ļ�β�ͽ���
			break;
		string s;//�������
		getline(filein, s);//����ÿһ��
		istringstream sin(s);
		string nu1;
		sin >> nu1 ;//��
		if (m == nu1)//�˺Ŵ���
		{
			i = true;
			filein.close();
			cout << "���鼮����" << endl;
			cout << "��ȷ��Ҫɾ�����鼮��Ϣ��" << endl;
			cout << "1:��  2:��" << endl;
			int temp;
			do
			{
				cin >> temp;
				if (temp == 1) {
					handle hero;
					hero.deletebook(m);//��������ɾ�����鼮��Ϣ
					cout << "ɾ�����" << endl;
				}
				else if (temp == 2)
				{
					break;
				}
				else
				{
					cout << "�����������������" << endl;
				}
			} while (temp != 1 && temp != 2);
		}
	} while (!filein.eof());//�ж��Ƿ��ļ�β


	if (i == 0)//δ�ҵ��˺�
	{
		cout << "���벻��ȷ�����鼮������" << endl;
		filein.close();
	}
}

void manage::addReader()//���Ӷ��ߺ���
{
	ofstream fout("student.txt", ios::app);//���ļ�
	string a, b, c;
	cout << "��������Ӧ��Ϣ��" << endl;
	cout << "������" << endl;
	cin >> a;
	cout << "ѧ�ţ�" << endl;
	cin >> b;
	cout << "���룺" << endl;
	cin >> c;
	fout << a << " " << b << " " << c << " " << endl;
	cout << "�����˺����" << endl;
	fout.close();//�ر��ļ�
}

void manage::deleteReader()
{
		string t, m;
		cout << "������ɾ��ѧ���ĵ�������" << endl;
		cin >> m;
		cout << "������ɾ��ѧ���ĵ�ѧ�ţ�" << endl;
		cin >> t;

		ifstream in("student.txt");//���ļ�
		bool i = 0;//��ǩ���ж��˺ŵĴ������
		do
		{
			if (in.eof())//�ļ�β�ͽ���
				break;
			string s;//�������
			getline(in, s);//����ÿһ��
			istringstream sin(s);
			string nu1, nu2;
			sin >> nu1 >> nu2;//��
			if ((m == nu1) && (t == nu2) )//�˺Ŵ���
			{
				i = true;
				in.close();
				cout << "��ѧ������" << endl;
				cout << "��ȷ��Ҫɾ����ѧ����Ϣ��" << endl;
				cout << "1:��  2:��" << endl;
				int temp;
				do
				{
					cin >> temp;
					if (temp == 1) {
						handle hero;
						hero.deletestu(t);//����ѧ��ɾ����ѧ����Ϣ
						cout << "ɾ�����" << endl;
					}
					else if (temp == 2)
					{
						break;
					}
					else
					{
						cout << "�����������������" << endl;
					}
				} while (temp != 1 && temp != 2);
			}
		} while (!in.eof());//�ж��Ƿ��ļ�β


		if (i == 0)//δ�ҵ��˺�
		{
			cout << "���벻��ȷ����ѧ��������" << endl;
			in.close();
		}
}

manage::~manage()//��������
{
}
