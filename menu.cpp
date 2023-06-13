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
		system("cls");//清除屏幕内容
		cout << "***************************" << endl;
		cout << "欢迎进入图书管理系统！" << endl;
		cout << "请选择以何种身份登录？" << endl;
		cout << "1.管理员" << endl;
		cout << "2.读者" << endl;
		cout << "3.退出" << endl;
		cout << "***************************" << endl;
		int t;
		do {
			cin >> t;
			switch (t)
			{
			case 1:display_2(); break;
			case 2:display_3(); break;
			case 3:
				cout << "感谢您的使用！" << endl;
				system("pause");
				exit(0);
			default:
				cout << "输入错误！请重新输入" << endl;
			}
		} while (t != 1 && t != 2 && t != 3);//防止输入错误
	}
}
void menu::display_2()
{

	while (true)
	{
		system("cls");
		cout << "***************************" << endl;
		cout << "欢迎进入图书管理系统！" << endl;
		cout << "1.登陆账号" << endl;
		cout << "2.修改管理员信息" << endl;
		cout << "3.退出" << endl;
		cout << "***************************" << endl;
		int t;
		do {
			cin >> t;
			switch (t)
			{
				mangerfun a1;//打开管理者功能类
			case 1:a1.getManage(); break;//调用getManage()函数
			case 2:a1.reviseInformation(); break;//调用reviseInformation()函数
			case 3:
				cout << "感谢您的使用！" << endl;
				system("pause");
				exit(0);
			default:
				cout << "输入错误,请重新输入" << endl;
			}
		} while (t != 1 && t != 2 && t != 3);
	}
}
void menu::display_3()
{
	while (true)
	{
		system("cls");//清除屏幕内容
		cout << "***************************" << endl;
		cout << "欢迎进入图书管理系统！" << endl;
		cout << "1.登陆账号" << endl;
		cout << "2.修改读者信息" << endl;
		cout << "3.退出" << endl;
		cout << "***************************" << endl;
		int t;
		do {
			cin >> t;
			switch (t)
			{
				readerfun b1;//打开读者功能类
			case 1:b1.getStudent(); break;
			case 2:b1.changeCode(); break;
			case 3:
				cout << "感谢您的使用！" << endl;//退出
				system("pause");
				exit(0);
			default:
				cout << "输入错误,请重新输入" << endl;//错误提示
			}
		} while (t !=1 &&t!=2&&t!=3);
	}

}