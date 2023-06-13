#include "manager.h"
#include"book.h"
#include"handle.h"
manage::manage()//析构函数
{

}

bool manage::getManage()//登录函数
{
	cout << "欢迎登陆图书管理系统！" << endl;
	string a, b;
	cout << "请输入账号：" << endl;
	cin >> a;
	cout << "请输入密码：" << endl;
	cin >> b;
	string n, c;
	ifstream in("manage.txt");//打开文件
	int i = 0;//标签，判断账号的存在与否
	do
	{
		if (in.eof())//文件尾就结束
			break;

		string s;
		getline(in, s);//读入每一行
		istringstream sin(s);
		sin >> n >> c;
		if ((a == n) && (c == b))//判断是否存在
		{
			i = 1;
			return 1;
			cout << "登陆成功！" << endl;
			break;

		}
	} while (!in.eof());//判断是否到文件尾

	if (i == 0)//未找到账号
		cout << "输入不正确！" << endl;
	return 0;
	in.close();//关闭文件
}

void manage::reviseInformation()//修改信息函数
{
	int t = 0;//标签，是否存在该账号
	string a, b, c, d;
	cout << "请输入个人信息：" << endl;
	cout << "账号：" << endl;
	cin >> c;
	cout << "密码：" << endl;
	cin >> d;
	ifstream in("manage.txt");//打开文件
	string s1;
	while (getline(in, s1))//读入数据
	{
		istringstream sin(s1);//定义sin流
		sin >> a >> b;
		
		if ((a == c) && (b == d))//存在该账号
		{
			cout << "该账号存在" << endl;
			t = 1;
			string m, p;
			cout << "请输入修改后的信息:" << endl;
			cout << "新账号：" << endl;
			cin >> m;
			cout << "新密码：" << endl;
			cin >> p;
			handle hero;
			hero.changemanageinformation(c, m, p);
			cout << "修改成功" << endl;
			return;
		}
		
	}
	in.close();//关闭文件
	cout << "***************************" << endl;
	cout << "账号不存在，正在为你新建一个账号" << endl;
	cout << "***************************" << endl;
	ofstream out("manage.txt", ios::app);//打开文件
	out << c << " " << d << endl;
	cout << "创建账号完成" << endl;
	out.close();

}

void manage::add()//定义添加书籍函数
{
	book book1;//实例化对象
	ofstream fileout("store.txt", ios::app);//打开文件
	if (!fileout)
	{
		cout << "不能打开文件！" << "store.txt" << endl;
	}
	else
	{
		cout << "请输入书本基本信息：" << endl;
		book1.readBookInformation();//读入信息
		fileout << book1.getName() << " " << book1.getbookAuthor() << " " << book1.getbookISBN() << " " << book1.gettype()
			<< " " << book1.getbookPress() << " " << book1.getbookStatue() << endl;//写入信息
	}
	fileout.close();//关闭文件

}

void manage::revise()//定义修改书籍信息函数
{
	book book1;//实例化对象
	ifstream filein("store.txt");//打开文件
	if (!filein)
	{
		cout << "打开文件失败！" << endl;
	}
	else
	{
		cout << "请输入修改书籍的的书名：" << endl;
		int n = 0;//标签，是否有这本书
		string t;//输入书名
		cin >> t;
		do
		{
			int v;//定义变量
			string x, y, z, u, w;
			string s;
			getline(filein, s);//读入每一行
			istringstream sin(s);
			sin >> x;//把s中第一个字符串给x

			if (t == x)//判断是否为修改的地方
			{
				n = 1;
				sin >> y >> z >> u >> w >> v;//将一行字符串读出
				book1.setName(x);//设定书名
				book1.setAuthor(y);//设定作者
				book1.setISBN(z);//设定ISBN码
				book1.settype(u);//设定书项
				book1.setPress(w);//设定出版社
				book1.setStatue(v);//设定状态
				cout << "原书籍信息为:" << endl;
				book1.printBookInformation();//输出

				cout << "请输入修改后的书籍信息：" << endl;
				book1.readBookInformation();//重新读入
				handle hero;
				hero.revisebookinformation(x, book1.getName(), book1.getbookAuthor(), book1.getbookISBN(), book1.gettype(), book1.getbookPress(), book1.getbookStatue());
				cout << "修改完成" << endl;
				break;
			}
		} while (!filein.eof());//判断是否到文件尾
		if (n == 0) {
			cout << "未找到要修改的书籍！" << endl;
		}
		filein.close();
	}
}


void manage::deleteBook()
{
	string  m;
	cout << "请输入删除书籍的名字：" << endl;
	cin >> m;

	ifstream filein("store.txt");//打开文件
	bool i = 0;//标签，判断账号的存在与否
	do
	{
		if (filein.eof())//文件尾就结束
			break;
		string s;//定义变量
		getline(filein, s);//读入每一行
		istringstream sin(s);
		string nu1;
		sin >> nu1 ;//拆开
		if (m == nu1)//账号存在
		{
			i = true;
			filein.close();
			cout << "该书籍存在" << endl;
			cout << "您确定要删除该书籍信息吗？" << endl;
			cout << "1:是  2:否" << endl;
			int temp;
			do
			{
				cin >> temp;
				if (temp == 1) {
					handle hero;
					hero.deletebook(m);//根据书名删除该书籍信息
					cout << "删除完成" << endl;
				}
				else if (temp == 2)
				{
					break;
				}
				else
				{
					cout << "输入错误，请重新输入" << endl;
				}
			} while (temp != 1 && temp != 2);
		}
	} while (!filein.eof());//判断是否到文件尾


	if (i == 0)//未找到账号
	{
		cout << "输入不正确，该书籍不存在" << endl;
		filein.close();
	}
}

void manage::addReader()//增加读者函数
{
	ofstream fout("student.txt", ios::app);//打开文件
	string a, b, c;
	cout << "请输入相应信息！" << endl;
	cout << "姓名：" << endl;
	cin >> a;
	cout << "学号：" << endl;
	cin >> b;
	cout << "密码：" << endl;
	cin >> c;
	fout << a << " " << b << " " << c << " " << endl;
	cout << "创建账号完成" << endl;
	fout.close();//关闭文件
}

void manage::deleteReader()
{
		string t, m;
		cout << "请输入删除学生的的姓名：" << endl;
		cin >> m;
		cout << "请输入删除学生的的学号：" << endl;
		cin >> t;

		ifstream in("student.txt");//打开文件
		bool i = 0;//标签，判断账号的存在与否
		do
		{
			if (in.eof())//文件尾就结束
				break;
			string s;//定义变量
			getline(in, s);//读入每一行
			istringstream sin(s);
			string nu1, nu2;
			sin >> nu1 >> nu2;//拆开
			if ((m == nu1) && (t == nu2) )//账号存在
			{
				i = true;
				in.close();
				cout << "该学生存在" << endl;
				cout << "您确定要删除该学生信息吗？" << endl;
				cout << "1:是  2:否" << endl;
				int temp;
				do
				{
					cin >> temp;
					if (temp == 1) {
						handle hero;
						hero.deletestu(t);//根据学号删除该学生信息
						cout << "删除完成" << endl;
					}
					else if (temp == 2)
					{
						break;
					}
					else
					{
						cout << "输入错误，请重新输入" << endl;
					}
				} while (temp != 1 && temp != 2);
			}
		} while (!in.eof());//判断是否到文件尾


		if (i == 0)//未找到账号
		{
			cout << "输入不正确，该学生不存在" << endl;
			in.close();
		}
}

manage::~manage()//析构函数
{
}
