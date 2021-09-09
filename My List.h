#pragma once
#include"Сотрудники.h"
#include "Item.h"

class MyList
{
	Sotrudniki* Head;
public:
	MyList() : Head(NULL) {};
	void AddToTop(Sotrudniki* st); // добавление записи в начало списка
	void AddToEnd(Sotrudniki* st); // добавление записи в конец списка
	void Show(); // вывод списка на экран
	void Clear(); // очистка списка (удаление всех эл.)
	bool LoadToFile(std::string file_name); // сохранение списка в файл
	bool ReadFromFile(std::string file_name); // чтение из файла в тот же список
	bool isEmpty() 
	{
		if (Head == NULL) return true;
		else return false;
	}
	void removeAt(Sotrudniki* st); // Удаляет определенный элемент списка
	void sortBycod_dol(int cod_dol); //Поиск по коду должности
	void sortBycod_sot(int cod_sot); //Поиск по коду сотрудника
	void showSotrudInfo(Sotrudniki* st); // вывод информации об ОДНОМ сотруднике
};


