#include "���������.h"
#include <iostream>
Position::Position() :dol_cod(0000), prof("defaultprof"), pay(0), need("defaultneed"),must("defaultmust"){}
Position::Position(int Tempdol_cod, string Tempprof,int Temppay, string Tempneed,string Tempmust):
	dol_cod(Tempdol_cod), prof(Tempprof), pay(Temppay), need(Tempneed), must(Tempmust) {}
void Position::SetConsole()
{
	cout << "������� ��� ���������:" << setw(5); cin >> dol_cod;
	cout << "������� ���������:" << setw(5); cin >>prof;
	cout << "������� ��������:" << setw(5); cin >> pay;
	cout << "������� �����������:" << setw(5); cin >> need;
	cout << "����������:" << setw(5); cin >> must;
}
bool Position::write(ofstream* fout) {
	//���� ���� �� ������
	if (!fout) return false;
	//����������
	fout->write((char*)this, sizeof(Position));
	if (fout->good())
		return true;
	else
		return false;
}
//����� ������ ������ �� �����
//����� ������ ���� ��� ������
bool Position::read(ifstream* fin) {
	//���� ���� �� ������
	if (!fin) return false;
	if (fin->peek() == EOF) return false;
	fin->read((char*)this, sizeof(Position));
	if (fin->good())
		return true;
	else
		return false;
}