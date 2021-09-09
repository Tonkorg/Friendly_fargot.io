#pragma once
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>

using namespace std;

class Style
{
	int cod_style;
	string name_style, discribe;
public:
	Style();
	Style(int cod_style, string name_style, string discribe);
	void SetConsole();
	//Сетеры и Гетеры
	void setcod_style(int d) { cod_style = d; }
	int getcod_style() { return cod_style; }
	void setname_style (string str) { name_style= str; }
	string getname_style() { return name_style; }
	void setdiscribe(string str) { discribe = str; }
	string getdiscribe() { return discribe; }

	friend ostream& operator << (ostream& out, Style& S) {
		return out << setw(15) << S.cod_style << setw(4) << S.name_style
			<< setw(15) << S.discribe << endl;
	}
	friend istream& operator >> (istream& in, Style& S) {
		in >> S.cod_style >> S.name_style >> S.discribe;
		return in;
	}
	//метод записи данных в файл
 //поток должен быть уже открыт
	bool write(std::ofstream* fout);
	//метод чтения данных из файла
	//поток должен быть уже открыт
	bool read(std::ifstream* fin);
};
