#pragma once


#ifndef READER_H
#define READER_H
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
class reader
{
private:
	string name;
	string number;
	string code;
public:
	reader(void);

	void setName(string n);
	void setNumber(string nu);
	void setCode(string c);

	string getName()const;
	string getNumber()const;
	string getCode()const;

	bool getInformation();
	void changeCode();//ÐÞ¸ÄÃÜÂë
	void search();
	void borrowBook();
	void returnBook();

	~reader(void);
};
#endif

