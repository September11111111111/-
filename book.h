#pragma once
#pragma 
#pragma once
#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<sstream>
#include<iomanip>
#define NULLID "0"
using namespace std;

class book
{
private:
	string bookName;
	string bookAuthor;
	string bookISBN;
	string type;
	string bookPress;
	bool bookStatue;


public:
	book();
	string getName()const;
	string getbookAuthor()const;
	string getbookISBN()const;
	string gettype()const;
	string getbookPress()const;
	bool getbookStatue()const;

	void setName(string a);
	void setAuthor(string b);
	void setISBN(string c);
	void settype(string d);
	void setPress(string e);
	void setStatue(int f);

	void readBookInformation();	
	void printBookInformation();
	void changeStatue();

	~book();

};
#endif



