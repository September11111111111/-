#include"mgrfun.h"
#include"manager.h"
void mangerfun::addbook()
{
	manage manage1;//实例化对象
	for (int temp = 1; temp;)//循环添加书籍
	{
		manage1.add();//调用manage类中的add（）函数
		cout << "是否继续添加书籍（1：是，2：否）" << endl;//判断是否循环
		int a;//定义变量
		do {
			cin >> a;
			if (a == 1) temp = 1;
			else if (a == 2) temp = 0;
			else
			{
				cout << "输入错误!请重新输入" << endl; temp = 1;//输入错误提示
			}
		} while (a != 1 && a != 2);
	}
}
void mangerfun::deletebook() {
	manage manage6;//实例化对象
	for (int temp = 1; temp;)//循环删除书籍
	{
		manage6.deleteBook();//调用manage类中的deleteBook()函数
		cout << "是否继续删除书籍（1：是，2：否）" << endl;//判断是否循环
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
void mangerfun::changebook() {
	manage manage2;//实例化对象
	for (int temp = 1; temp;)//循环修改书籍
	{
		manage2.revise();//调用manage类中revise（）函数
		cout << "是否继续修改（1：是，2：否）" << endl;//循环判断
		int a;//定义变量
		do {
			cin >> a;
			if (a == 1) temp = 1;
			else if (a == 2) temp = 0;
			else
			{
				cout << "输入错误，请重新输入！" << endl;
			}
		} while (a != 1 && a != 2);
	}
}
void mangerfun::addReader()
{
	manage manage3;//实例化对象
	for (int a = 1; a != 2;)//循环增加
	{
		manage3.addReader();//调用manage类中addReader（）函数
		cout << "是否继续添加读者（1：是，2：否）" << endl;//循环判断
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
				cout << "输入错误，请重新输入！" << endl;
			}
		} while (a != 1 && a != 2);
	}
}
void mangerfun::deleteReader()
{
	manage manage7;//实例化对象
	for (int temp = 1; temp;)//循环删除
	{
		manage7.deleteReader();//调用manage类中deleteReader（）函数
		cout << "是否继续删除读者（1：是，2：否）" << endl;//循环判断
		int a;//定义变量
		do {
			cin >> a;
			if (a == 1) temp = 1;
			else if (a == 2) temp = 0;
			else
			{
				cout << "输入错误，请重新输入！" << endl;
			}
		} while (a != 1 && a != 2);
	}
}
void mangerfun::getManage()
{
	manage manage4;//实例化对象
	int max_attempts = 3;
	for (int temp = 1, attempt = 0; temp && attempt < max_attempts; attempt++)//循环登陆
	{
		int b;//接受getManage()的返回值
		b = manage4.getManage();//调用manage类中的getManage()函数
		if (b == 1)//登陆成功
		{
			while (true)
			{
				system("cls");//清除屏幕内容
				cout << "***************************" << endl;
				cout << "欢迎进入图书管理系统！" << endl;
				cout << "请选择相应功能：" << endl;
				cout << "1.增加读者" << endl;
				cout << "2.删除读者" << endl;
				cout << "3.增加书籍信息" << endl;
				cout << "4.删除书籍信息" << endl;
				cout << "5.修改书籍信息" << endl;
				cout << "6.退出" << endl;
				int t;
				int temp = 0;
				do {
					if (temp) {
						cout << "输入错误，请重新输入！";
					}
					cin >> t;
					temp++;
				} while (t != 1 && t != 2 && t != 3 && t != 4 && t != 5 && t != 6);
				switch (t)
				{
				case 1:addReader(); break;//调用addReader()函数
				case 2:deleteReader(); break;//调用deleteReader()函数
				case 3:addbook(); break;//调用addbook()函数
				case 4:deletebook(); break;//调用deletebook()函数
				case 5:changebook(); break;//调用changebook()函数
				case 6:
					cout << "感谢您的使用！" << endl;//退出
					system("pause");
					exit(0);
				}

			}

		}

		else//登录失败判断是否再次登陆
		{
			if (attempt < max_attempts - 1)
			{
				cout << "是否继续登陆（1：是，2：否）" << endl;//循环判断
				int  a;//定义变量
				do {
					cin >> a;
					if (a == 1)
					{
						temp = 1;

					}
					else if (a == 2) temp = 0;
					else
					{
						cout << "输入错误!" << endl; //输入错误提示
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
void mangerfun::reviseInformation()
{
	manage manage5;//实例化对象
	for (int temp = 1; temp;)//循环修改
	{
		manage5.reviseInformation();//调用manage类中的reviseInformation()函数
		cout << "是否继续修改（1：是，2：否）" << endl;//循环判断
		int  a;//定义变量
		do {
			cin >> a;
			if (a == 1) temp = 1;
			else if (a == 2) temp = 0;
			else
			{
				cout << "输入错误，请重新输入" << endl; 
			}
		} while (a != 1 && a != 2);
	}
}