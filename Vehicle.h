#pragma once

#include<iostream>

using namespace std;

class Vehicle
{
public:
	Vehicle(int w, int d);
	Vehicle(int w);
	Vehicle();

	Vehicle(Vehicle&);
	Vehicle(Vehicle*);

	~Vehicle();

	void setNumWheels(int w);
	void setNumDoors(int d);

	void printVehicle(void);

private:
	int numWheels;
	int numDoors;

};