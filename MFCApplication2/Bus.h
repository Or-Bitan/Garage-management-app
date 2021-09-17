#pragma once
#include "Private_car.h"
class Bus :public PrivateCar
{
public:
	CString tier;
	Bus(CString owner_name, int km, int year, CString color, int plate_number, CString Model, CString type, CString tier);
	~Bus();
	Bus();



	string ToString();


};

