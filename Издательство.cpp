#include "������������.h"
#include <iostream>

Isdatelstvo::Isdatelstvo() :cod_isd(0000), name_isd("defaultname_isd"), city_isd("defaultcity_isd"),street_isd("default otch"){}
Isdatelstvo::Isdatelstvo (int Tempcod_isd, string Tempname_isd, string Tempcity_isd, string Tempstreet_isd):
	cod_isd(Tempcod_isd), name_isd(Tempname_isd), city_isd(Tempcity_isd), street_isd(Tempstreet_isd) {}
void Isdatelstvo::SetConsole()
{
	cout << "������� ��� ������������" << setw(5); cin >> cod_isd;
	cout << "������� ��� ������������:" << setw(5); cin >> name_isd;
	cout << "������� ����� ������������:" << setw(5); cin >> city_isd;
	cout << "������� ����� :" << setw(5); cin >> street_isd;
}
bool Isdatelstvo::write(ofstream* fout) {
	//���� ���� �� ������
	if (!fout) return false;
	//����������
	fout->write((char*)this, sizeof(Isdatelstvo));
	if (fout->good())
		return true;
	else
		return false;
}
//����� ������ ������ �� �����
//����� ������ ���� ��� ������
bool Isdatelstvo::read(ifstream* fin) {
	//���� ���� �� ������
	if (!fin) return false;
	if (fin->peek() == EOF) return false;
	fin->read((char*)this, sizeof (Isdatelstvo));
	if (fin->good())
		return true;
	else
		return false;
}