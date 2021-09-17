#include "pch.h"
#include "Plane.h"
#include "iomanip"
#include "iostream"
#include "string"
using namespace std;


Plane::Plane(int engines,CString owner_name,int year, CString color, int plate_number, CString Model, CString type) :Vehicle( year,  color,  plate_number,  Model,  type)
{
	this->Engines = engines;
	this->owner_name = owner_name;
}

Plane::Plane() :Vehicle()
{


}

Plane::~Plane() 
{


}
string Plane::ToString()
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
	string e = to_string(Engines);
	v += " year:" + s + " color:" + color + " plate:" + to_string(plate_number) +" number of engines:" +e;

	return v;
}