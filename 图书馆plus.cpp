#include"book.h"
#include"manager.h"
#include"reader.h"
#include"menu.h"
#include<iostream>
using namespace std;
int main()
{
	while (1)
	{
		menu a1;
		a1.display_1();//调用display_1()函数
		system("pause");
	}
	return 0;
}
