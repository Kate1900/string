#pragma once
#include <iostream>

using namespace std;

class Stroka 
{
private:
	char* nov;
	int length;
	int size;
public:
	Stroka();

	Stroka(char b, int leng);

	Stroka(const char* tstr);

	Stroka(Stroka& a);

	~Stroka();

	char* get_s()
	{
		return nov;
	}
	int get_l()
	{
		return length;
	}
	void set_s(const char* s);

	friend Stroka operator +(Stroka& a, Stroka& b);

	Stroka& operator =(const Stroka& a);

	void complete(Stroka& a, Stroka& b);

	friend bool operator == (Stroka& a, Stroka& b);

	friend bool operator <(Stroka& a, Stroka& b);

	friend bool operator >(Stroka& a, Stroka& b);

	char& operator [](const int index);

	friend ostream& operator <<(ostream& out, Stroka& a);

	friend istream& operator >> (istream& in, Stroka& b);

	char* find(const char* e);

	char* find_c(const char* c);

	Stroka* Tstrtok(const char* c);



	Stroka repeater(Stroka& s, int n);

};
