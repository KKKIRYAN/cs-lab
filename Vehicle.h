#ifndef VEHICLE_H
#define VEHICLE_H

#pragma once

#include <iostream>

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

	Vehicle& operator=(const Vehicle&);

	bool operator==(const Vehicle&);
	bool operator!=(const Vehicle&);

	Vehicle& operator++();

	Vehicle& operator--();

	friend ostream& operator<<(ostream&, const Vehicle& v);

	virtual float calculateRange() = 0;
	virtual float percentEnergyRemaining() = 0;
	virtual void drive(float km) = 0;

private:
	int numWheels;
	int numDoors;
};

#endif
