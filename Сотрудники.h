	#pragma once
	#include <iostream>
	#include <string.h>
	#include <iomanip>
	#include <fstream>

	using namespace std;

	class Sotrudniki
	{
		int cod_sot, cod_dol, number, age;
		string name, Lastname, otch, sex, street, pasp;
	public:
		Sotrudniki();
		Sotrudniki(int cod_sot, string name, string Lastname, string otch, int age, string sex, string street, int number, string pasp, int cod_dol);
		void SetConsole();
		//Сетеры и Гетеры
		void setcod_sot(int d) { cod_sot = d; }
		int getcod_sot() { return cod_sot; }
		void setname(string str) { name = str; }
		string getname() { return name; }
		void setLastname(string str) { Lastname = str; }
		string getLastname() { return Lastname; }
		void setotch(string str) { otch = str; }
		string getotch() { return otch; }
		void setage(int num) { age = num; }
		int getage() { return age; }
		void setsex(string str) { sex = str; }
		string getsex() { return sex; }
		void setstreet(string str) { street = str; }
		string getstreet() { return street; }
		void setnumber(int num) { number = num; }
		int getnumber() { return number; }
		void setpasp(string str) { pasp = str; }
		string getpasp() { return pasp; }
		void setcod_dol(int num) { cod_dol = num; }
		int getcod_dol() { return cod_dol; }
		void setConsole();

		friend ostream& operator << (ostream& out, Sotrudniki& S) {
			return out << setw(15) << S.cod_sot << setw(4) << S.name
				<< setw(20) << S.Lastname << setw(3) << S.otch
				<< setw(3) << S.age << setw(5) << S.sex <<setw(5)<<S.street<<setw(8)<<S.number<<setw(10)<<S.pasp<<setw(4)<<S.cod_dol<<
				endl;
		}
		friend istream& operator >> (istream& in, Sotrudniki& S) {
			in >> S.cod_sot >> S.name
				>> S.Lastname >> S.otch
				>> S.age >> S.sex >> S.street >> S.number >> S.pasp >> S.cod_dol;
			return in;
		}
		//метод записи данных в файл
	 //поток должен быть уже открыт
		bool write(std::ofstream* fout);
		//метод чтения данных из файла
		//поток должен быть уже открыт
		bool read(std::ifstream* fin);
	};

