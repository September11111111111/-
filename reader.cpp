#include "reader.h"
#include"book.h"
#include"handle.h"
#include<vector>

reader::reader()
{
	name = "δ����";

}

string reader::getName()const//�������
{
	return name;
}

string reader::getNumber()const//���ѧ��
{
	return number;
}

string reader::getCode()const//�������
{
	return code;
}

void reader::setName(string n)//�趨����
{
	name = n;
}

void reader::setNumber(string nu)//�趨ѧ��
{
	number = nu;
}

void reader::setCode(string c)//�趨����
{
	code = c;
}

bool reader::getInformation()//��֤��Ϣ
{
	cout << "��ӭ��½ͼ�����ϵͳ��" << endl;
	string a, b, t;
	cout << "������������" << endl;
	cin >> a;
	cout << "������ѧ�ţ�" << endl;
	cin >> b;
	cout << "���������룺(��ʼ����Ϊѧ��)" << endl;
	cin >> t;

	string n, nu, c;

	ifstream in("student.txt");//���ļ�
	int i = 0;//��ǩ���ж��˺ŵĴ������
	do
	{
		if (in.eof())//�ļ�β�ͽ���
			break;
		string s;//�������
		getline(in, s);//����ÿһ��
		istringstream sin(s);
		sin >> n >> nu >> c;//��
		if ((a == n) && (b == nu) && (c == t))//�˺Ŵ���
		{
			i = true;
			cout << "��½�ɹ���" << endl;
			in.close();
			return 1;
			break;
		}
	} while (!in.eof());//�ж��Ƿ��ļ�β


	if (i == 0)//δ�ҵ��˺�
	{
		cout << "���벻��ȷ��" << endl;
		in.close();
		return 0;
	}
}

void reader::changeCode()//�޸�����
{
	int t = 0;//��ǩ���ж��˺��Ƿ����
	string a, b, c, d, e, f;//�������
	cout << "�����������Ϣ��" << endl;
	cout << "����:" << endl;
	cin >> d;
	cout << "ѧ�ţ�" << endl;
	cin >> e;
	cout << "���룺(��ʼ����Ϊѧ��)" << endl;
	cin >> f;
	ifstream in("student.txt");//���ļ�
	string s1;
	while (getline(in, s1))//��������
	{
		istringstream sin(s1);//����sin1��
		sin >> a >> b >> c;
		if ((a == d) && (b == e) && (c == f))//�ж��Ƿ�������ȷ
		{
			t = 1;
			string q;//�������
			cout << "�������޸ĺ����Ϣ:" << endl;
			cout << "�����룺" << endl;
			cin >> q;
			handle hero;
			hero.changepassword(d, q);
			cout << "�޸ĳɹ�" << endl;
			in.close();
			return;
		}
		
		
	}
		cout << "***************************" << endl;
		cout << "�˺Ų����ڣ�����ϵ��ʦ�����˺�" << endl;
		cout << "***************************" << endl;
	in.close();//�ر��ļ�
}

void reader::search()//�����ѯ����
{
	book book1;//ʵ��������
	ifstream filein("store.txt"); //���ļ�
	if (!filein.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
	}
	else
	{
		cout << "�������ѯ��������" << endl;
		string t;//��������
		cin >> t;
		int m = 0;//��ǩ���ж��Ƿ����Ȿ��
		string s;
		while (getline(filein, s))
		{
			int v;
			string a, x, y, z, u, w;
			istringstream sin(s);

			while (getline(sin, a, ' '))
			{
				if (a == t)
				{
					m++;
					sin >> y >> z >> u >> w >> v;

					book1.setName(a);
					book1.setAuthor(y);
					book1.setISBN(z);
					book1.settype(u);
					book1.setPress(w);
					book1.setStatue(v);

					book1.printBookInformation();
					break;
				}
			}
		}
		if (m == 0) // if the book was not found
			cout << "δ�ҵ�Ҫ���ҵ��鼮��" << endl;

		filein.close();
	}
}



void reader::borrowBook()//������麯��
{
	book book2;//ʵ��������
	cout << "�������鼮���ƣ�" << endl;
	ifstream filein("store.txt");//���ļ�
	string t;//��������
	cin >> t;
	int m = 0;
	string s;
	while (getline(filein, s))//�ж϶��������
	{
		int v;
		string a;//����ÿ�еĿ�ͷ
		string x, y, z, u, w;

		istringstream sin(s);
		sin >> a;
		if (t == a)//�ж��Ƿ��ҵ�����鼮
		{
			m++;
			x = a;
			sin >> y >> z >> u >> w >> v;//��һ���ַ�������
			vector<string> books = { x, y, z, u, w, to_string(v) };
			if (!v) {
				book2.setName(x);//�趨����
				book2.setAuthor(y);//�趨����
				book2.setISBN(z);//�趨ISBN��
				book2.settype(u);//�趨����
				book2.setPress(w);//�趨������
				book2.setStatue(v);//�趨״̬
				book2.printBookInformation();//���

				handle hero;
				hero.borrow(x);//��1�޸�Ϊ0,���õ��޸������ļ�
				cout << "***************************" << endl;
				cout << "�ѽ�����밴ʱ�黹" << endl;
				cout << "***************************" << endl;
				return;
			}
			else
			{
				cout << "���鱾�ѽ�������ڹ��ڡ�" << endl;
				filein.close();
			}
			return;
		}
	}
	cout << "δ�ҵ����鼮��" << endl;
}
	

void reader::returnBook()//���廹�麯��
{
	book book3;//ʵ��������
	cout << "�������鼮���ƣ�" << endl;
	ifstream filein("store.txt");//���ļ�
	string t;//��������
	cin >> t;
	string s;
	while(getline(filein, s))//�ж϶��������
	{
		int v;
		string a;//����ÿ�еĿ�ͷ
		string x, y, z, u, w;
		istringstream sin(s);
		sin >> a;
		if (t == a)//�ж��Ƿ��ҵ�����鼮
		{
			x = a;
			cout << a << endl;
			sin >> y >> z >> u >> w >> v;//��һ���ַ�������
			if (v) {
				book3.setName(x);//�趨����
				book3.setAuthor(y);//�趨����
				book3.setISBN(z);//�趨ISBN��
				book3.settype(u);//�趨����
				book3.setPress(w);//�趨������
				book3.setStatue(v);//�趨״̬
				book3.printBookInformation();//���
				handle hero;
				hero.returnchange(x);//��1��Ϊ0
				cout << "��л���Ĺ黹����ӭ���´�������" << endl;
				filein.close();
				return;
			}
			else
			{
				cout << "�����Ѿ��黹�����Ƿ��������"<<endl;
				filein.close();
				return;
			}
		}
	} 
		cout << "δ�ҵ�Ҫ�����鼮��" << endl;
		filein.close();
}

reader::~reader()
{
}

