#include <iostream>
#include <fstream>
#include <iomanip>
#include "Item.h"
#include "My List.h"
#include "Сотрудники.h"


using namespace std;

int main()
{
	setlocale(0, "");
	int choice;
	MyList spisok;
	bool flag = true; // флаг продолжения работы
	while (flag)
	{
		system("cls"); // очистка экрана
		cout << " MENU" << endl;
		cout << "_____________________" << endl;
		cout << "1: Показать список" << endl;
		cout << "2: Добавить запись" << endl;
		cout << "3: Создать запрос" << endl;
		cout << "4: Выход" << endl;
		cout << "_____________________" << endl << endl;
		cout << "Выберите пункт (1-4): ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			std::cout << "__________MENU__________\n\n"
				<< "1: Сотрудники\n"
				<< "2: Должности\n"
				<< "3: Издательства\n"
				<< "4: Жанры\n"
				<< "5: Книги\n"
				<< "6: Читатели\n"
				<< "7: Выданные книги\n"
				<< "8: Назад\n"
				<< "________________________\n\n"
				<< "Выберите пункт 1-8: ";
			cin >> choice;
			system("cls");
			switch (choice)	
			{
			case 1:
			{
				system("cls");
			spisok.Show(); system("PAUSE"); break;



}