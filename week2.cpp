
#include<iostream>


/*

4.	Implement 3 different public constructors:	(look at slides 28 & 29)
a)	Vehicle( int w, int d ) // constructor for the number of wheels and doors
You should be setting numWheels to w, and numDoors to d.

b)	Vehicle( int w) // this should call constructor a) with parameters doors = 4, and wheels = w. In other words, call: Vehicle(4, w)

c)	Vehicle() // empty constructor. This should call constructor b) with wheels = 4. Constructor c) should call b), which itself calls constructor a).

*/


using namespace std;

class Vehicle
{
public:
	Vehicle(int w, int d)
	{
		numWheels = w;
		numDoors = d;
		cout << "In constructor with 2 parameters" << endl;
	}

	Vehicle(int w): Vehicle(w, 4)
	{
		cout << "In constructor with 1 parameters, wheels = " << w << endl;
	}

	Vehicle(): Vehicle(4)
	{
		cout << "In constructor with 0 parameters" << endl;
	}

	~Vehicle()
	{
		cout << "In destructor" << endl;
	}

private:
	int numWheels;
	int numDoors;

};

int main(int argc, char **argv)
{
   std::cout << "Hello World!" << std::endl;

   Vehicle myVehicle(4); //This calls constructor Vehicle(int);
   std::cout << "I made a vehicle!" << std::endl;


   return 0;
}