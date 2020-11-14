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



	Vehicle& operator=(const Vehicle&);

	bool operator==(const Vehicle&);
	bool operator!=(const Vehicle&);

	Vehicle& operator++();
	Vehicle& operator++(int);

	Vehicle& operator--();
	Vehicle& operator--(int);

	friend ostream& operator<<(ostream&, const Vehicle& v);

private:
	int numWheels;
	int numDoors;

};