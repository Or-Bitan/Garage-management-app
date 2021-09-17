//#pragma once
//class Vehicle
//{
//};

#pragma once
#include <string.h>
#include <iomanip>
#include<iostream>

using namespace std;

class Vehicle :public CObject
{
public:
	//DECLARE_SERIAL(Vehicle)
	int year;
	CString color;
  int plate_number;
	CString Model;
	CString type;
	//public:
public:

	Vehicle();
	Vehicle(const Vehicle& v);
	Vehicle(int year, CString color, int plate_number, CString Model, CString type);
	virtual ~Vehicle();
	int get_year() const { return year; };
	CString get_color() const { return color; };
	 int get_plate_number()const { return plate_number; };
	CString get_Model()const { return Model; };
	CString get_type()const { return type; };
	void set_Model(CString Model) { this->Model = Model; };
	void set_type(CString type) { this->type = type; };
	void set_plate_number(long int plate_number) { this->plate_number = plate_number; };
	void set_year(int year) { this->year = year; };
	void set_color(CString color) { this->color = color; };
	void insert_Vehicle(const Vehicle& v);
	void remove_Vechile(const Vehicle& v);
	void Display_Vechile();
	Vehicle& operator =(Vehicle& other);
	virtual string ToString();

	/*virtual void Serialize(CArchive& ar);*/

};

