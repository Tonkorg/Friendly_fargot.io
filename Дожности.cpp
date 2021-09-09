#include "Должности.h"
#include <iostream>
Position::Position() :dol_cod(0000), prof("defaultprof"), pay(0), need("defaultneed"),must("defaultmust"){}
Position::Position(int Tempdol_cod, string Tempprof,int Temppay, string Tempneed,string Tempmust):
	dol_cod(Tempdol_cod), prof(Tempprof), pay(Temppay), need(Tempneed), must(Tempmust) {}
void Position::SetConsole()
{
	cout << "Введите код должности:" << setw(5); cin >> dol_cod;
	cout << "Введите профессию:" << setw(5); cin >>prof;
	cout << "Введите зарплату:" << setw(5); cin >> pay;
	cout << "Введите обязанности:" << setw(5); cin >> need;
	cout << "Требования:" << setw(5); cin >> must;
}
bool Position::write(ofstream* fout) {
	//Если файл не открыт
	if (!fout) return false;
	//записываем
	fout->write((char*)this, sizeof(Position));
	if (fout->good())
		return true;
	else
		return false;
}
//метод чтения данных из файла
//поток должен быть уже открыт
bool Position::read(ifstream* fin) {
	//Если файл не открыт
	if (!fin) return false;
	if (fin->peek() == EOF) return false;
	fin->read((char*)this, sizeof(Position));
	if (fin->good())
		return true;
	else
		return false;
}