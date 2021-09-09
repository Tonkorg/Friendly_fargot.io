#include "My List.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>

using namespace std;

void MyList::Clear()
{
	while (Head != NULL) //���� �� ������ ���� ���� ���-��
	{
		Item* temp = Head->next; //����� �����. ��������� �� ����� ����. �������� ���������
		delete Head; //����������� ������ �� ����� ������ ������
		Head = temp; //������ ����� ������ ������
	}
	Head = NULL;
}

void MyList::AddToTop(Sotrudniki* st)
{
	Item* temp = new Item(st); //��������� ������ ��� ����� �������
	temp->next = Head; //���������, ��� ����� ���������� �������� ��� ������ ������ ������
		Head = temp; //����� ������ ������ ������
}


void MyList::AddToEnd(Sotrudniki* st)
{
	Item* tmpNewItem = new Item(st); //��������� ������ ��� ����� �������
	//���� ������ ������, �� ����� ��. ��� ������ ������
	if (Head == NULL) {
		Head = tmpNewItem;
		return;
	}
	//���� ������ �� ������, �� ��������� �� ��������� ��. � ��������� � �����
	Item* p = Head;
	while (p->next != NULL) {
		p = p->next;
	}
	//������ p ��������� �� ��������� ��-�
	p->next = tmpNewItem; //��������� ����� ��-� � �����
}

bool MyList::ReadFromFile(string file_name)
{
	//���� ��� ����� �����������
	if (file_name == "") return false;
	ifstream fin(file_name);
	//���� ���� �� ������
	if (!fin) return false;
	// ����� ���� ������ ------------------
	Clear(); // ������� ������ ��������
	//� ����� ������ �� ����� � ��������� � ����� ������
	Sotrudniki tmpStud;
	while (!fin.eof()) {
		if (fin.peek() != EOF) {
			fin >> tmpStud;
		}
		AddToEnd(&tmpStud);
	}
	fin.close(); //��������� ����
	return true;
}

void MyList::Show()
{
	Item* temp = Head; //��������� ���������, �� ��������� �� ������
	system("cls"); // �������������
	cout << setw(15) << "��� ����������" << setw(4) << "���" <<
		setw(11) << "�������" << setw(20) << "��������" << setw(20) << "�������" << setw(3) << "���" << setw(4) << "������" << setw(16) << "�����" << setw(12)
		<< "��������� ������" << setw(12) << "��� ���������" << endl; // ��������������
	cout << "_______________________________________"
		<< endl << endl;
	while (temp != NULL) //���� �� ������ �� ������ ���� ������
	{
		//������� ��� �������� ���������
		cout << setw(15) << temp->data.getcod_sot();
		cout << setw(4) << temp->data.getname();
		cout << setw(11) << temp->data.getLastname();
		cout << setw(20) << temp->data.getotch();
		cout << setw(20) << temp->data.getage();
		cout << setw(3) << temp->data.getsex();
		cout << setw(4) << temp->data.getstreet();
		cout << setw(16) << temp->data.getnumber();
		cout << setw(12) << temp->data.getpasp();
		cout << setw(12) << temp->data.getcod_dol();
		cout << endl;
		//��������� �� ��������� ����� �� ������
		temp = temp->next;
	}
	cout << "________________________________________" << endl << endl;
}

void MyList::sortBycod_sot() {
	Sotrudniki reader;
	Item* temp = Head;
	Item* temp2 = temp->next;
	while (temp->next != NULL) {
		temp2 = temp->next;
		while (temp2 != NULL) {
			if (temp->data.getcod_sot() > temp2->data.getcod_sot()) {
				reader = temp->data;
				temp->data = temp2->data;
				temp2->data = reader;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}


