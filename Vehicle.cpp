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
