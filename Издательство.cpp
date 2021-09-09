#include "Издательства.h"
#include <iostream>

Isdatelstvo::Isdatelstvo() :cod_isd(0000), name_isd("defaultname_isd"), city_isd("defaultcity_isd"),street_isd("default otch"){}
Isdatelstvo::Isdatelstvo (int Tempcod_isd, string Tempname_isd, string Tempcity_isd, string Tempstreet_isd):
	cod_isd(Tempcod_isd), name_isd(Tempname_isd), city_isd(Tempcity_isd), street_isd(Tempstreet_isd) {}
void Isdatelstvo::SetConsole()
{
	cout << "Введите код издательства" << setw(5); cin >> cod_isd;
	cout << "Введите имя издательства:" << setw(5); cin >> name_isd;
	cout << "Введите город издательства:" << setw(5); cin >> city_isd;
	cout << "Введите улицу :" << setw(5); cin >> street_isd;
}
bool Isdatelstvo::write(ofstream* fout) {
	//Если файл не открыт
	if (!fout) return false;
	//записываем
	fout->write((char*)this, sizeof(Isdatelstvo));
	if (fout->good())
		return true;
	else
		return false;
}
//метод чтения данных из файла
//поток должен быть уже открыт
bool Isdatelstvo::read(ifstream* fin) {
	//Если файл не открыт
	if (!fin) return false;
	if (fin->peek() == EOF) return false;
	fin->read((char*)this, sizeof (Isdatelstvo));
	if (fin->good())
		return true;
	else
		return false;
}