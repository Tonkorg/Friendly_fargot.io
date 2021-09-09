#pragma once
#include "Сотрудники.h"
#include "Должности.h"
#include "Издательства.h"
#include "Жанры.h"
struct Sot
{
	Sotrudniki data;
	Sot* next;
	Sot(Sotrudniki* st)
	{
		data.setcod_sot(st->getcod_sot());
		data.setname(st->getname());
		data.setLastname(st->getLastname());
		data.setotch(st->getotch());
		data.setage(st->getage());
		data.setsex(st->getsex());
		data.setstreet(st->getstreet());
		data.setnumber(st->getnumber());
		data.setpasp(st->getpasp());
		data.setcod_dol(st->getcod_dol());
		next = NULL;		
	}
};

struct Doll
{
	Position data;
	Doll* next;
	Doll(Position* st)
	{
		data.setdol_cod(st->getdol_cod());
		data.setprof(st->getprof());
		data.setpay(st->getpay());
		data.setneed(st->getneed());
		data.setmust(st->getmust());
		next = NULL;
	}
};

struct Isd
{
	Isdatelstvo data;
	Isd* next;
		Isd(Isdatelstvo* st)
	{
		data.setcod_isd(st->getcod_isd());
		data.setname_isd(st->getname_isd());
		data.setcity_isd(st->getcity_isd());
		data.setstreet_isd(st->getstreet_isd());
		next = NULL;
	}
};
struct St
{
	Style data;
	St* next;
	St(Style* st)
	{
		data.setcod_style(st->getcod_style());
		data.setname_style(st->getname_style());
		data.setdiscribe(st->getdiscribe());
		next = NULL;
	}
};