#pragma once
#include"����������.h"
#include "Item.h"

class MyList
{
	Sotrudniki* Head;
public:
	MyList() : Head(NULL) {};
	void AddToTop(Sotrudniki* st); // ���������� ������ � ������ ������
	void AddToEnd(Sotrudniki* st); // ���������� ������ � ����� ������
	void Show(); // ����� ������ �� �����
	void Clear(); // ������� ������ (�������� ���� ��.)
	bool LoadToFile(std::string file_name); // ���������� ������ � ����
	bool ReadFromFile(std::string file_name); // ������ �� ����� � ��� �� ������
	bool isEmpty() 
	{
		if (Head == NULL) return true;
		else return false;
	}
	void removeAt(Sotrudniki* st); // ������� ������������ ������� ������
	void sortBycod_dol(int cod_dol); //����� �� ���� ���������
	void sortBycod_sot(int cod_sot); //����� �� ���� ����������
	void showSotrudInfo(Sotrudniki* st); // ����� ���������� �� ����� ����������
};


