#pragma once
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>

using namespace std;

class Isdatelstvo
{
	int cod_isd;
	string name_isd, street_isd, city_isd;
public:
	Isdatelstvo();
	Isdatelstvo(int cod_isd, string name_isd, string city_isd, string street_isd);
	void SetConsole();
	//Сетеры и Гетеры
	void setcod_isd(int d) { cod_isd = d; }
	int getcod_isd() { return cod_isd; }
	void setname_isd(string str) { name_isd = str; }
	string getname_isd() { return name_isd; }
	void setstreet_isd(string str) { street_isd = str; }
	string getstreet_isd() { return street_isd; }
	void setcity_isd (string str) { city_isd = str; }
	string getcity_isd() { return city_isd; }
	

	friend ostream& operator << (ostream& out, Isdatelstvo& S) {
		return out << setw(15) << S.cod_isd << setw(4) << S.name_isd
			<< setw(15) << S.city_isd << setw(20) << S.street_isd <<endl;
	}
	friend istream& operator >> (istream& in, Isdatelstvo& S) {
		in >> S.cod_isd >> S.name_isd >> S.city_isd
			>> S.street_isd;
		return in;
	}
	//метод записи данных в файл
 //поток должен быть уже открыт
	bool write(std::ofstream* fout);
	//метод чтения данных из файла
	//поток должен быть уже открыт
	bool read(std::ifstream* fin);
};
