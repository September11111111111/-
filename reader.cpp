#include "reader.h"
#include"book.h"
#include"handle.h"
#include<vector>

reader::reader()
{
	name = "未命名";

}

string reader::getName()const//获得姓名
{
	return name;
}

string reader::getNumber()const//获得学号
{
	return number;
}

string reader::getCode()const//获得密码
{
	return code;
}

void reader::setName(string n)//设定姓名
{
	name = n;
}

void reader::setNumber(string nu)//设定学号
{
	number = nu;
}

void reader::setCode(string c)//设定密码
{
	code = c;
}

bool reader::getInformation()//验证信息
{
	cout << "欢迎登陆图书管理系统！" << endl;
	string a, b, t;
	cout << "请输入姓名：" << endl;
	cin >> a;
	cout << "请输入学号：" << endl;
	cin >> b;
	cout << "请输入密码：(初始密码为学号)" << endl;
	cin >> t;

	string n, nu, c;

	ifstream in("student.txt");//打开文件
	int i = 0;//标签，判断账号的存在与否
	do
	{
		if (in.eof())//文件尾就结束
			break;
		string s;//定义变量
		getline(in, s);//读入每一行
		istringstream sin(s);
		sin >> n >> nu >> c;//拆开
		if ((a == n) && (b == nu) && (c == t))//账号存在
		{
			i = true;
			cout << "登陆成功！" << endl;
			in.close();
			return 1;
			break;
		}
	} while (!in.eof());//判断是否到文件尾


	if (i == 0)//未找到账号
	{
		cout << "输入不正确！" << endl;
		in.close();
		return 0;
	}
}

void reader::changeCode()//修改密码
{
	int t = 0;//标签，判断账号是否存在
	string a, b, c, d, e, f;//定义变量
	cout << "请输入个人信息：" << endl;
	cout << "姓名:" << endl;
	cin >> d;
	cout << "学号：" << endl;
	cin >> e;
	cout << "密码：(初始密码为学号)" << endl;
	cin >> f;
	ifstream in("student.txt");//打开文件
	string s1;
	while (getline(in, s1))//读入数据
	{
		istringstream sin(s1);//定义sin1流
		sin >> a >> b >> c;
		if ((a == d) && (b == e) && (c == f))//判断是否输入正确
		{
			t = 1;
			string q;//定义变量
			cout << "请输入修改后的信息:" << endl;
			cout << "新密码：" << endl;
			cin >> q;
			handle hero;
			hero.changepassword(d, q);
			cout << "修改成功" << endl;
			in.close();
			return;
		}
		
		
	}
		cout << "***************************" << endl;
		cout << "账号不存在，请联系老师创建账号" << endl;
		cout << "***************************" << endl;
	in.close();//关闭文件
}

void reader::search()//定义查询函数
{
	book book1;//实例化对象
	ifstream filein("store.txt"); //打开文件
	if (!filein.is_open())
	{
		cout << "打开文件失败！" << endl;
	}
	else
	{
		cout << "请输入查询的书名：" << endl;
		string t;//输入书名
		cin >> t;
		int m = 0;//标签，判断是否有这本书
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
			cout << "未找到要查找的书籍！" << endl;

		filein.close();
	}
}



void reader::borrowBook()//定义借书函数
{
	book book2;//实例化对象
	cout << "请输入书籍名称：" << endl;
	ifstream filein("store.txt");//打开文件
	string t;//输入书名
	cin >> t;
	int m = 0;
	string s;
	while (getline(filein, s))//判断读入的书名
	{
		int v;
		string a;//读出每行的开头
		string x, y, z, u, w;

		istringstream sin(s);
		sin >> a;
		if (t == a)//判断是否找到借的书籍
		{
			m++;
			x = a;
			sin >> y >> z >> u >> w >> v;//将一行字符串读出
			vector<string> books = { x, y, z, u, w, to_string(v) };
			if (!v) {
				book2.setName(x);//设定书名
				book2.setAuthor(y);//设定作者
				book2.setISBN(z);//设定ISBN码
				book2.settype(u);//设定书项
				book2.setPress(w);//设定出版社
				book2.setStatue(v);//设定状态
				book2.printBookInformation();//输出

				handle hero;
				hero.borrow(x);//把1修改为0,采用的修改整个文件
				cout << "***************************" << endl;
				cout << "已借出，请按时归还" << endl;
				cout << "***************************" << endl;
				return;
			}
			else
			{
				cout << "该书本已借出，不在馆内。" << endl;
				filein.close();
			}
			return;
		}
	}
	cout << "未找到该书籍。" << endl;
}
	

void reader::returnBook()//定义还书函数
{
	book book3;//实例化对象
	cout << "请输入书籍名称：" << endl;
	ifstream filein("store.txt");//打开文件
	string t;//输入书名
	cin >> t;
	string s;
	while(getline(filein, s))//判断读入的书名
	{
		int v;
		string a;//读出每行的开头
		string x, y, z, u, w;
		istringstream sin(s);
		sin >> a;
		if (t == a)//判断是否找到借的书籍
		{
			x = a;
			cout << a << endl;
			sin >> y >> z >> u >> w >> v;//将一行字符串读出
			if (v) {
				book3.setName(x);//设定书名
				book3.setAuthor(y);//设定作者
				book3.setISBN(z);//设定ISBN码
				book3.settype(u);//设定书项
				book3.setPress(w);//设定出版社
				book3.setStatue(v);//设定状态
				book3.printBookInformation();//输出
				handle hero;
				hero.returnchange(x);//将1改为0
				cout << "感谢您的归还，欢迎您下次再来！" << endl;
				filein.close();
				return;
			}
			else
			{
				cout << "该书已经归还，您是否输入错误"<<endl;
				filein.close();
				return;
			}
		}
	} 
		cout << "未找到要还的书籍！" << endl;
		filein.close();
}

reader::~reader()
{
}

