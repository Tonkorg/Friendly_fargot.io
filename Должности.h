#pragma once
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>

using namespace std;

class Position
{
	int dol_cod, pay;
	string prof, need, must;
public:
	Position();
	Position(int dol_cod, string prof, int pay, string need, string must);
	void SetConsole();
	//Сетеры и Гетеры
	void setdol_cod(int d) { dol_cod = d; }
	int getdol_cod() { return dol_cod; }
	void setprof(string str) { prof = str; }
	string getprof() { return prof; }
	void setpay(int str) { pay = str; }
	int getpay() { return pay;}
	void setneed(string str) {need= str; }
	string getneed() { return need; }
	void setmust(string str) { must = str; }
	string getmust() { return must; }


	friend ostream& operator << (ostream& out,Position& S) {
		return out << setw(15) << S.dol_cod<< setw(4) << S.prof
			<< setw(20) << S.pay << setw(5) << S.need
			<< setw(20) << S.must <<
			endl;
	}
	friend istream& operator >> (istream& in,Position& S) {
		in >> S.dol_cod >> S.prof
			>> S.pay >> S.need
			>> S.must;
		return in;
	}
	//метод записи данных в файл
 //поток должен быть уже открыт
	bool write(std::ofstream* fout);
	//метод чтения данных из файла
	//поток должен быть уже открыт
	bool read(std::ifstream* fin);
};