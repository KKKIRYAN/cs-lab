#include<iostream>

#include "Vehicle.h"

/*

4.	Implement 3 different public constructors:	(look at slides 28 & 29)
a)	Vehicle( int w, int d ) // constructor for the number of wheels and doors
You should be setting numWheels to w, and numDoors to d.

b)	Vehicle( int w) // this should call constructor a) with parameters doors = 4, and wheels = w. In other words, call: Vehicle(4, w)

c)	Vehicle() // empty constructor. This should call constructor b) with wheels = 4. Constructor c) should call b), which itself calls constructor a).

*/


using namespace std;


void CreateVehicle(Vehicle& v, int w = 4, int d = 2)
{
	v.setNumWheels(w);
	v.setNumDoors(d);
}



int main(int argc, char** argv)
{
	Vehicle original;    //empty constructor no ( )

	Vehicle copy(original); // copy constructor by reference
	Vehicle secondCopy(&original); //copy constructor by pointer

	copy.printVehicle();
	CreateVehicle(copy, 2); //wheels is 2, everything else is default value
	copy.printVehicle();
	CreateVehicle(copy, 2, 3); //wheels is 2, doors is 3
	copy.printVehicle();
	copy = secondCopy;
	copy.printVehicle();	// copy is same as second copy
	return 0;
}



int main_backup(int argc, char **argv)
{
	
	int d, w;
	std::string ans;
	Vehicle* pVehicle;

	do {
		cout << "enter number of doors" << endl;
		cin >> d;
		cout << "enter number of wheels" << endl;
		cin >> w;

		pVehicle = new Vehicle(w, d);
		delete pVehicle;

		cout << "Do you want to create a new vehicle or quit" << endl;
		cin >> ans;
	}
	while (ans != "q");


	Vehicle veh1; // This calls constructor Vehicle()
	cout << "Vehicle takes " << sizeof(veh1) << endl;

	Vehicle veh2(4); //This calls constructor Vehicle(int);
	cout << "Vehicle takes " << sizeof(veh2) << endl;

	Vehicle veh3(4, 2); //This calls constructor Vehicle( int, int);
	cout << "Vehicle takes " << sizeof(veh3) << endl;

	std::cout << "I made a vehicle!" << std::endl;

	// Vehicle veh4 = veh3;

	Vehicle secondCopy(&veh3);

	// Vehicle* veh5 = &veh3;


	return 0;
}