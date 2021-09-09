#include "Сотрудники.h"
#include <iostream>
Sotrudniki::Sotrudniki() :cod_sot(0000), name("defaultName"), Lastname("defaultLastnsme"), otch("default otch"), age(0), sex("defaultsex"), street("defaultstreet"), 
number(00000000000), pasp("defaultpasp"), cod_dol(0000) {}
Sotrudniki::Sotrudniki(int Tempcod_sot, string Tempname,string TempLastname,string Tempotch,int Tempage,string Tempsex,string Tempstreet,int Tempnumber,string Temppasp,int Tempcod_dol):
	cod_sot(Tempcod_sot), name(Tempname),Lastname(TempLastname),otch(Tempotch),age(Tempage),sex(Tempsex), street(Tempstreet),number(Tempnumber), pasp(Temppasp),cod_dol(Tempcod_dol){}
void Sotrudniki::SetConsole()
{
	cout << "Введите код сотрудника:" << setw(5); cin >> cod_sot;
	cout << "Введите имя:" << setw(5); cin >> name;
	cout << "Введите фамилию:" << setw(5); cin >> Lastname;
	cout << "Введите отчество:" << setw(5); cin >> otch;
	cout << "Введите возраст:" << setw(5); cin >> age;
	cout << "Введите пол:" << setw(5); cin >> sex;
	cout << "Введите улицу проживания:" << setw(5); cin >> street;
	cout << "Введите номер телефона:" << setw(5); cin >> number;
	cout << "Введите данные паспорта ( серия + номер):" << setw(5); cin >> pasp;
	cout << "Введите код должности:" << setw(5); cin >> cod_dol;

}
bool Sotrudniki::write(ofstream* fout) {
	//Если файл не открыт
	if (!fout) return false;
	//записываем
	fout->write((char*)this, sizeof(Sotrudniki));
	if (fout->good())
		return true;
	else
	return false;
}
//метод чтения данных из файла
//поток должен быть уже открыт
bool Sotrudniki::read(ifstream* fin) {
	//Если файл не открыт
	if (!fin) return false;
	if (fin->peek() == EOF) return false;
	fin->read((char*)this, sizeof(Sotrudniki));
	if (fin->good())
		return true;
	else
		return false;
}