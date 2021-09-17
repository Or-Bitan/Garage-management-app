#include "pch.h"
#include "Bus.h"
#include<iomanip>
#include <iostream>
#include <string>
using namespace std;
Bus::Bus(CString owner_name, int km, int year, CString color, int plate_number, CString Model, CString type, CString tier) :PrivateCar(owner_name, km, year, color, plate_number, Model, type)
{

	this->tier = tier;




}
Bus::Bus() :PrivateCar()
{
	tier = "";

}
Bus::~Bus()
{

}

string Bus::ToString()
{
	CT2A ct(owner_name);
	string str(ct);

	CT2A ct1(Model);
	string model(ct1);
	CT2A ct2(color);
	string color(ct2);

	CT2A ct3(type);
	string type(ct3);
	CT2A ct4(tier);
	string t(ct4);
	string v;
	v = "model:" + model;
	v += " name:" + str;
	v += " type:" + type;
	string s = to_string(year);
	v += " year:" + s + " color:" + color + " plate:" + to_string(plate_number) + " tier: " +t;

	return v;
}
