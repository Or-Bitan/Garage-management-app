//#pragma once
//class Private_car
//{
//};

#pragma once
#include "Vehicle.h"
#include <iomanip>

class PrivateCar :public Vehicle
{
public:
	CString owner_name;
	int km;
public:


	//DECLARE_SERIAL(PrivateCar);
	PrivateCar();
	PrivateCar(CString owner_name, int km, int year, CString color, int plate_number, CString Model, CString type);
	~PrivateCar();
	virtual string ToString();

	/*virtual void Serialize(CArchive& archive);*/


};