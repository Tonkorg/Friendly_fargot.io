#include "����������.h"
#include <iostream>
Sotrudniki::Sotrudniki() :cod_sot(0000), name("defaultName"), Lastname("defaultLastnsme"), otch("default otch"), age(0), sex("defaultsex"), street("defaultstreet"), 
number(00000000000), pasp("defaultpasp"), cod_dol(0000) {}
Sotrudniki::Sotrudniki(int Tempcod_sot, string Tempname,string TempLastname,string Tempotch,int Tempage,string Tempsex,string Tempstreet,int Tempnumber,string Temppasp,int Tempcod_dol):
	cod_sot(Tempcod_sot), name(Tempname),Lastname(TempLastname),otch(Tempotch),age(Tempage),sex(Tempsex), street(Tempstreet),number(Tempnumber), pasp(Temppasp),cod_dol(Tempcod_dol){}
void Sotrudniki::SetConsole()
{
	cout << "������� ��� ����������:" << setw(5); cin >> cod_sot;
	cout << "������� ���:" << setw(5); cin >> name;
	cout << "������� �������:" << setw(5); cin >> Lastname;
	cout << "������� ��������:" << setw(5); cin >> otch;
	cout << "������� �������:" << setw(5); cin >> age;
	cout << "������� ���:" << setw(5); cin >> sex;
	cout << "������� ����� ����������:" << setw(5); cin >> street;
	cout << "������� ����� ��������:" << setw(5); cin >> number;
	cout << "������� ������ �������� ( ����� + �����):" << setw(5); cin >> pasp;
	cout << "������� ��� ���������:" << setw(5); cin >> cod_dol;

}
bool Sotrudniki::write(ofstream* fout) {
	//���� ���� �� ������
	if (!fout) return false;
	//����������
	fout->write((char*)this, sizeof(Sotrudniki));
	if (fout->good())
		return true;
	else
	return false;
}
//����� ������ ������ �� �����
//����� ������ ���� ��� ������
bool Sotrudniki::read(ifstream* fin) {
	//���� ���� �� ������
	if (!fin) return false;
	if (fin->peek() == EOF) return false;
	fin->read((char*)this, sizeof(Sotrudniki));
	if (fin->good())
		return true;
	else
		return false;
}