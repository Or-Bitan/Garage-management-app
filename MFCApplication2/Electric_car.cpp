#include "pch.h"
#include "Electric_car.h"
#include <string>
#include <iomanip>
using namespace std;


Electric_car::Electric_car(CString owner_name, int km, int year, CString color, int plate_number, CString Model, int batteryage, CString type) :PrivateCar(owner_name,  km,  year,  color,  plate_number,  Model,type)
{

	this->batteryAge = batteryage;
}


Electric_car::Electric_car() :PrivateCar()
{
	batteryAge = 0;

}
Electric_car::Electric_car(const  Electric_car &other) :PrivateCar()
{

	this->batteryAge = other.batteryAge;



}

Electric_car::~Electric_car()
{


}

string Electric_car::ToString()
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
		string battery=to_string(batteryAge);
		v += " year:" + s + " color:" + color + " plate:" + to_string(plate_number) + "battery age:" + battery;

		return v;
	
}

Electric_car& Electric_car::operator=(const Electric_car& other)
{

	this->batteryAge = other.batteryAge;
	return*this;

}

//void Electric_car::Serialize(CArchive& archive)
//{
//	CObject::Serialize(archive);
//
//	// now do the stuff for our specific class
//	if (archive.IsStoring())
//		archive << batteryAge;
//	else
//		archive >> batteryAge;
//
//
//}