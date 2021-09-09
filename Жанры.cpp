#include "Жанры.h"
#include <iostream>

Style::Style() :cod_style(0000), name_style("defaultname_style"), discribe("defaultdiscribe") {}
Style::Style(int Tempcod_style, string Tempname_style, string Tempdiscribe) :
	cod_style(Tempcod_style), name_style(Tempname_style), discribe(Tempdiscribe) {}
void Style::SetConsole()
{
	cout << "Введите код жанра"<<setw(5); cin >> cod_style;
	cout << "Введите название издательства" << setw(5); cin >> name_style;
	cout << "Добавьте описание:" << setw(5); cin >> discribe;
}
bool Style::write(ofstream* fout) {
	//Если файл не открыт
	if (!fout) return false;
	//записываем
	fout->write((char*)this, sizeof(Style));
	if (fout->good())
		return true;
	else
		return false;
}
//метод чтения данных из файла
//поток должен быть уже открыт
bool Style ::read(ifstream* fin) {
	//Если файл не открыт
	if (!fin) return false;
	if (fin->peek() == EOF) return false;
	fin->read((char*)this, sizeof(Style));
	if (fin->good())
		return true;
	else
		return false;
}