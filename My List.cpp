#include "My List.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>

using namespace std;

void MyList::Clear()
{
	while (Head != NULL) //Пока по адресу есть хоть что-то
	{
		Item* temp = Head->next; //Сразу запом. указатель на адрес след. элемента структуры
		delete Head; //Освобождаем память по месту начала списка
		Head = temp; //Меняем адрес начала списка
	}
	Head = NULL;
}

void MyList::AddToTop(Sotrudniki* st)
{
	Item* temp = new Item(st); //Выделение памяти под новый элемент
	temp->next = Head; //Указываем, что адрес следующего элемента это старое начало списка
		Head = temp; //Смена адреса начала списка
}


void MyList::AddToEnd(Sotrudniki* st)
{
	Item* tmpNewItem = new Item(st); //Выделение памяти под новый элемент
	//если список пустой, то новый эл. это голова списка
	if (Head == NULL) {
		Head = tmpNewItem;
		return;
	}
	//если список не пустой, то переходим на последний эл. и добавляем в конец
	Item* p = Head;
	while (p->next != NULL) {
		p = p->next;
	}
	//теперь p указывает на последний эл-т
	p->next = tmpNewItem; //добавляем новый эл-т в конец
}

bool MyList::ReadFromFile(string file_name)
{
	//если имя файла отсутствует
	if (file_name == "") return false;
	ifstream fin(file_name);
	//Если файл не открыт
	if (!fin) return false;
	// когда файл открыт ------------------
	Clear(); // удаляем старые элементы
	//в цикле читаем из файла и добавляем в конец списка
	Sotrudniki tmpStud;
	while (!fin.eof()) {
		if (fin.peek() != EOF) {
			fin >> tmpStud;
		}
		AddToEnd(&tmpStud);
	}
	fin.close(); //Закрываем файл
	return true;
}

void MyList::Show()
{
	Item* temp = Head; //Объявляем указатель, он указывает на начало
	system("cls"); // очисткаэкрана
	cout << setw(15) << "Код сотрудника" << setw(4) << "Имя" <<
		setw(11) << "Фамилия" << setw(20) << "Отчество" << setw(20) << "Возраст" << setw(3) << "Пол" << setw(4) << "Адресс" << setw(16) << "Номер" << setw(12)
		<< "Папортные данные" << setw(12) << "Код должности" << endl; // выводзаголовка
	cout << "_______________________________________"
		<< endl << endl;
	while (temp != NULL) //Пока по адресу на начало есть данные
	{
		//Выводим все элементы структуры
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
		//Переходим на следующий адрес из списка
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


