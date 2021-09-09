#include "Книги.h"
#include <iostream>

Book::Book() :cod_book(0), book_name("defaultbook_name"), writer("defaultwriter"), isd_cod(0), year(0), style_cod("defaultstyle_cod") {}
Book::Book(int Tempcod_book, string Tempbook_name, string Tempwriter,int Tempisd_cod, int Tempyear, string Tempstyle_cod):
	cod_book(Tempcod_book), book_name(Tempbook_name), writer(Tempwriter),isd_cod (Tempisd_cod),year(Tempyear),style_cod(Tempstyle_cod) {}
void Book::SetConsole()
{
	cout << "Введите код книги" << setw(5); cin >> cod_book;
	cout << "Введите название книги" << setw(5); cin >> book_name;
	cout << "Введите автора:" << setw(5); cin >> writer;
	cout << "Введите код издательства:" << setw(5); cin >> isd_cod;
	cout << "Введите код издательства" << setw(5); cin >> year;
	cout << "Введите код жанра" << setw(5); cin >> style_cod;
	
}
bool Book::write(ofstream* fout) {
	//Если файл не открыт
	if (!fout) return false;
	//записываем
	fout->write((char*)this, sizeof(Book));
	if (fout->good())
		return true;
	else
		return false;
}
//метод чтения данных из файла
//поток должен быть уже открыт
bool Book::read(ifstream* fin) {
	//Если файл не открыт
	if (!fin) return false;
	if (fin->peek() == EOF) return false;
	fin->read((char*)this, sizeof(Book));
	if (fin->good())
		return true;
	else
		return false;
}