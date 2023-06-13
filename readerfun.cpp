#include"readerfun.h"
#include"reader.h"

void readerfun::search()
{
	reader reader3;//实例化对象
	reader3.search();//调用reader类中的search()函数
	cout << "是否继续查询（1：是，2：否）" << endl;//循环判断
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
			cout << "输入错误，请重新输入！" << endl;
		}
	} while (a != 1 && a != 2);
}
void readerfun::borrowBook()
{
	reader reader4;//实例化对象
	for(int a=1;a!=2;){
		reader4.borrowBook();//调用reader类中的borrowBook()函数
		cout << "是否继续借书（1：是，2：否）" << endl;//循环判断
		do {
			cin >> a;
			if (a == 1)
			{
				reader4.borrowBook();
			}
			else if (a == 2) return;
			else
			{
				cout << "输入错误，请重新输入！" << endl;
			}
		} while (a != 1 && a != 2);
		}
}
void readerfun::changeCode()
{
	reader reader6;//实例化对象
	for (int a = 1; a != 2;)//循环修改密码
	{
		reader6.changeCode();//调用reader类中的changeCode()函数
		cout << "是否继续修改（1：是，2：否）" << endl;//循环判断
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
				cout << "输入错误，请重新输入！" << endl;//输入错误提示
			}
		} while (a != 1 && a != 2);
	}
}
void readerfun::returnBook() {
	reader reader5;//实例化对象
	for (int temp = 1; temp;)//循环还书
	{
		reader5.returnBook();//调用reader类中的returnBook()函数
		cout << "是否继续还书（1：是，2：否）" << endl;//循环判断
		int a;//定义变量
		cin >> a;
		do {
			if (a == 1) temp = 1;
			else if (a == 2) temp = 0;
			else
			{
				cout << "输入错误，请重新输入！" << endl;
				temp = 1;//输入错误提示
			}
		} while (a != 1 && a != 2);
	}
}

void readerfun::getStudent()//用于登录账号
{
	reader reader5;
	int max_attempts = 3; // 最大尝试次数
	for (int temp = 1, attempt = 0; temp && attempt < max_attempts; attempt++)
	{
		int a;//接受getInformation()的返回值
		a = reader5.getInformation();//调用reader类中的getInformation()函数
		if (a == 1)//登陆成功
		{
			while (true)
			{
				system("cls");//清除屏幕内容
				cout << "***************************" << endl;
				cout << "欢迎进入图书管理系统！" << endl;
				cout << "请选择相应功能：" << endl;
				cout << "1.查询书籍信息" << endl;
				cout << "2.借阅书籍" << endl;
				cout << "3.返还书籍" << endl;
				cout << "4.退出" << endl;
				cout << "***************************" << endl;
				int t;
				int temp = 0;
				do {
					if (temp) {
						cout << "输入错误，请重新输入！";
					}
					cin >> t;
					temp++;
				} while (t != 1 && t != 2 && t != 3 && t != 4);
				switch (t)
				{
				case 1:search(); break;//调用search()函数
				case 2:borrowBook(); break;//调用borrowBook()函数
				case 3:returnBook(); break;//调用returnBook()函数
				case 4:
					cout << "感谢您的使用！" << endl;//退出
					system("pause");
					exit(0);
				}
			}
		}
		else
		{
			if (attempt < max_attempts - 1)
			{
				cout << "是否继续输入（1：是，2：否）" << endl;//循环判断
				int a;//定义变量
				cin >> a;
				do {
					if (a == 1) temp = 1;
					else if (a == 2) temp = 0;
					else
					{
						cout << "输入错误，请重新输入！" << endl;
						temp = 1;//输入错误提示
					}
				} while (a != 1 && a != 2);
			}
			else
			{
				cout << "你已经尝试了三次，登录失败!" << endl;
				temp = 0;
			}
		}
	}
}
