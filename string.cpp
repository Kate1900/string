#include "string.h"
#pragma warning(disable:4996)

Stroka::Stroka() :nov(0), size(0), length(0)
{

}

Stroka::Stroka(char b, int leng) {
	size = leng + 1;
	nov = new char[size];
	length = leng;
	for (int i = 0; i < length; i++) nov[i] = b;
	nov[length] = 0;
}

Stroka::Stroka(const char* tstr) {
	if (strlen(tstr) > 0) {

		size = strlen(tstr) + 1;
		length = strlen(tstr);
		nov = new char[strlen(tstr) + 1];
		for (size_t i = 0; i < strlen(tstr); i++)nov[i] = tstr[i];
		nov[strlen(tstr)] = 0;
	}

}

Stroka::Stroka(Stroka& a) {
	size = a.get_l() + 1;
	length = a.get_l();
	nov = new char[size];
	for (int i = 0; i < length; i++)nov[i] = a.get_s()[i];
	nov[length] = 0;
}

Stroka::~Stroka() {
	if (nov != NULL)
		delete[] nov;
}

void Stroka::set_s(const char* s) {
	if (strlen(s) > 0) {
		size = strlen(s) + 1;
		length = strlen(s);
		nov = new char[strlen(s) + 1];
		for (size_t i = 0; i < strlen(s); i++)nov[i] = s[i];
		nov[strlen(s)] = 0;
	}
}

Stroka operator +(Stroka& a, Stroka& b) {
	Stroka c(a);
	c.complete(a, b);
	return c;
}

Stroka& Stroka::operator =(const Stroka& a) {
	if (&a == this)
		return *this;
	length = a.length;
	size = length + 1;
	nov = new char[size];
	for (int i = 0; i < length; i++)nov[i] = a.nov[i];
	nov[length] = 0;
	return *this;
}

bool operator == (Stroka& a, Stroka& b) {
	return(0 == strcmp(a.get_s(), b.get_s()));
}

bool operator <(Stroka& a, Stroka& b) {
	return(strcmp(a.get_s(), b.get_s()) < 0);
}

bool operator >(Stroka& a, Stroka& b) {
	return(strcmp(a.get_s(), b.get_s()) > 0);
}

char& Stroka::operator [](const int index) {
	if (index < 0 || index >= length)
		throw "yikes";
	else
		return nov[index];
}

ostream& operator <<(ostream& out, Stroka& a) {
	for (int i = 0; i < a.get_l(); i++) {
		out << a.get_s()[i];
	}

	return out;
}

istream& operator >> (istream& in, Stroka& b) {
	char t[256];
	in.getline(t, 256);
	Stroka e(t);
	b = e;
	return in;
}

char* Stroka::find(const char* e) {
	char* t = strstr(nov, e);
	if (t != NULL)
		return t;
	else
		return (char*)"Not found";
}

char* Stroka::find_c(const char* c) {
	char* t = strstr(nov, c);
	if (t != NULL)
		return t;
	else
		return (char*)"Not found";
}

Stroka* Stroka::Tstrtok(const char* c) {
	int count = 0;

	Stroka tmp = nov;

	char* istr = strtok(tmp.nov, c);
	while (istr != NULL)
	{
		count += 1;
		istr = strtok(NULL, c);
	}

	tmp = nov;

	Stroka* result = new Stroka[count];

	count = 0;

	istr = strtok(tmp.nov, c);
	while (istr != NULL)
	{
		result[count] = istr;
		count += 1;
		istr = strtok(NULL, c);
	}

	return result;
}

void Stroka::complete(Stroka& a, Stroka& b)
{

	nov = new char[a.get_l() + 1 + b.get_l()];
	length = a.get_l() + b.get_l();
	size = a.get_l() + 1 + b.get_l();
	for (int i = 0; i < a.get_l(); i++) nov[i] = a.get_s()[i];
	for (int i = 0; i < b.get_l(); i++) nov[i + a.get_l()] = b.get_s()[i];
	nov[a.get_l() + b.get_l()] = 0;
}






Stroka Stroka::repeater(Stroka& s, int k)// Метод дубликации строки k раз
{
	if (s.get_l() == 0)
		throw "Length = 0";
	Stroka res(s);
	for (int i = 0; i < k - 1; i++)
	{
		res = res + s;
	}
	return res;
}