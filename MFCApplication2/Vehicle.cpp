#include "pch.h"
#include "Vehicle.h"
#include <string>


Vehicle::Vehicle()
{
	year = 0;
	plate_number = 0;

}
Vehicle::Vehicle(const Vehicle& v)
{

	set_year(v.get_year());
	set_color(v.get_color());
	set_plate_number(v.get_plate_number());
	set_Model(v.get_Model());

}
Vehicle::Vehicle(int year, CString color,  int plate_number, CString Model, CString type)
{
	set_year(year);
	set_color(color);
	set_plate_number(plate_number);
	set_Model(Model);
	set_type(type);

}

Vehicle::~Vehicle()
{


}

string Vehicle::ToString()
{
	CT2A ct1(Model);
	string model(ct1);
	CT2A ct2(color);
	string color(ct2);

	CT2A ct3(type);
	string type(ct3);

	string v;
	v = "model:" + model;
	string s = to_string(year);
	v += " year:" + s + " color:" + color + " plate:" + to_string(plate_number);

	return v;
}




//string IntToString(long int num) {
//	
//	while (num > 10)
//	{
//		int digit = num % 10;
//
//
//
// }


Vehicle& Vehicle:: operator=(Vehicle& other)
{

	set_year(other.get_year());
	set_color(other.get_color());
	set_plate_number(other.get_plate_number());
	set_Model(other.get_Model());

	return *this;
}




//
//void Vehicle::Serialize(CArchive& archive)
//{
//	// call base class function first
//	// base class is CObject in this case
//	CObject::Serialize(archive);
//	
//	// now do the stuff for our specific class
//	if (archive.IsStoring())
//		archive << plate_number << year;
//	else
//		archive >> plate_number >> year;
//}