#pragma once


#pragma once
#include "Private_Car.h"
class Electric_car :public PrivateCar 
{
private:

public:
	int batteryAge;
	Electric_car(CString owner_name, int km, int year, CString color, int plate_number, CString Model,int batteryage, CString type);
	Electric_car();
	Electric_car(const  Electric_car& other);//copy const
	~Electric_car();
	virtual string ToString();
	Electric_car& operator=(const Electric_car& other);
	int get_battery() { return batteryAge; };
};

