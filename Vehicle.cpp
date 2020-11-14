#include<iostream>

#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(int w, int d)
{
	numWheels = w;
	numDoors = d;
	cout << "In constructor with 2 parameters" << endl;
}

Vehicle::Vehicle(int w) : Vehicle(w, 4)
{
	cout << "In constructor with 1 parameters, wheels = " << w << endl;
}

Vehicle::Vehicle() : Vehicle(4)
{
	cout << "In constructor with 0 parameters" << endl;
}

Vehicle::Vehicle(Vehicle& copy)
{
	numWheels = copy.numWheels;
	numDoors = copy.numDoors;
	cout << "copy by reference" << endl;
}

Vehicle::Vehicle(Vehicle* copy)
{
	numWheels = copy->numWheels;
	numDoors = copy->numDoors;
	cout << "copy by pointer" << endl;
}


Vehicle& Vehicle::operator=(const Vehicle& v)
{
	numWheels = v.numWheels;
	numDoors = v.numDoors;
	return *this;
}

bool Vehicle::operator==(const Vehicle& v)
{
	cout << numWheels << " " << v.numWheels << endl;
	cout << numDoors << " " << v.numDoors << endl;

	return numWheels == v.numWheels && numDoors == v.numDoors;
}

bool Vehicle::operator!=(const Vehicle& v)
{
	return numWheels != v.numWheels || numDoors != v.numDoors;
}

Vehicle& Vehicle::operator++()
{
	numWheels = numWheels + 1;
	numDoors = numDoors + 1;
	return *this;
}

Vehicle& Vehicle::operator++(int)
{
	Vehicle temp = *this;
	++* this;
	return temp;
}

Vehicle& Vehicle::operator--()
{
	numWheels = numWheels - 1;
	numDoors = numDoors - 1;
	return *this;
}

Vehicle& Vehicle::operator--(int)
{
	Vehicle temp = *this;
	--* this;
	return temp;
}

ostream& operator<<(ostream& os, const Vehicle& v)
{
	os << "Vehicle at address: " << &v <<
		" numWheels: " << v.numWheels <<
		" numDoors: " << v.numDoors << endl;
	return os;
}


Vehicle::~Vehicle()
{
	cout << "In destructor" << endl;
}

void Vehicle::printVehicle()
{
	cout << "Vehicle at address: " << this <<
		" numWheels: "<< numWheels <<
		" numDoors: " << numDoors << endl;
}


void Vehicle::setNumWheels(int w)
{
	numWheels = w;
}

void Vehicle::setNumDoors(int d)
{
	numDoors = d;
}
