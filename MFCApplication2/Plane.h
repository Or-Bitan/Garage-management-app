#pragma once
#include "Vehicle.h"
class Plane :public Vehicle
{

public:
	int Engines;
	CString owner_name;
	Plane();
	Plane(int engines, CString owner_name, int year, CString color, int plate_number, CString Model, CString type);
	~Plane();
	string ToString();




};

