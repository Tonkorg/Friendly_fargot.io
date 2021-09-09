#pragma once
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>

using namespace std;

class Book
{
	int cod_book, year, isd_cod;
	string book_name, writer, style_cod;
public:
	Book();
	Book(int cod_book, string book_name, string writer, int isd_cod, int year, string style_cod );
	void SetConsole();
	//Сетеры и Гетеры
	void setcod_book(int d) { cod_book = d; }
	int getcod_book() { return cod_book;}
	void setwriter(string str) { writer = str; }
	string getwriter() { return writer; }
	void setstyly_cod(string str) { style_cod = str; }
	string getstyle_cod() { return style_cod; }
	void setyear(int d) { year = d; }
	int getyear() { return year; }
	void book_name(string str) { book_name = str; }
	string getbook_name() { return book_name; }
	void setstyle_cod(string str) { style_cod = str; }
	string getstyle_cod() { return style_cod; }
	void setisd_cod(int d) { isd_cod = d; }
	int getisd_cod() { return isd_cod; }

	friend ostream& operator << (ostream& out, Book& S) {
		return out << setw(15) << S.cod_book << setw(4) << S.book_name
			<< setw(15) << S.writer<<setw(15)<<S.isd_cod<<setw(4)<<S.year<<setw(4)<<S.style_cod << endl;
	}
	friend istream& operator >> (istream& in, Book& S) {
		in >> S.cod_book >> S.book_name >> S.writer>>S.isd_cod>>S.year>>S.style_cod;
		return in;
	}
	//метод записи данных в файл
 //поток должен быть уже открыт
	bool write(std::ofstream* fout);
	//метод чтения данных из файла
	//поток должен быть уже открыт
	bool read(std::ifstream* fin);
};
