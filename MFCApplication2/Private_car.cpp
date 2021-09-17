#include "pch.h"
#include "Private_car.h"
#include<string>

using namespace std;

PrivateCar::PrivateCar(CString owner_name, int km, int year, CString color,  int plate_number, CString Model, CString type) :Vehicle(year, color, plate_number, Model, type)
{
	this->km = km;
	this->owner_name = owner_name;

}

PrivateCar::PrivateCar() :Vehicle()
{
	km = 0;
	year = 0;
	color = "";
	plate_number = 0;
	Model = "";
	type = "";
}

PrivateCar::~PrivateCar()
{

}
string PrivateCar::ToString()
{
	CT2A ct(owner_name);
	string str(ct);

	CT2A ct1(Model);
	string model(ct1);
	CT2A ct2(color);
	string color(ct2);

	CT2A ct3(type);
	string type(ct3);
	string v;
	v = "model:" + model;
	v += " name:" + str;
	v += " type:" + type;
	string s = to_string(year);
	v += " year:" + s + " color:" + color + " plate:" + to_string(plate_number);

	return v;
}




//void PrivateCar::Serialize(CArchive& archive)
//{
//	// call base class function first
//	// base class is CObject in this case
//
//	/*int year;
//	string color;
//	long int plate_number;
//	string Model;
//	string type;*/
//	CObject::Serialize(archive);
//	// now do the stuff for our specific class
//	if (archive.IsStoring())
//		archive << plate_number << year << Model << type;
//	else
//		archive >> plate_number >> owner_name >> type >>Model;
//}

