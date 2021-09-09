#pragma once
#include <string>
#include <fstream>
#include <iomanip>

class table
{
public:
	std::string filename;
	std::string structname;

	table(std::string sn)
	{
	filename = makeFullWay(sn);
	structname = sn;
	}
	std::string makeFullWay(std::string sn)
	{
		return "C:\\Users\\User\\Documents\\Недохакер\\Practika 2 sem\\Файлы\\" + sn + ".txt";
	}
};
