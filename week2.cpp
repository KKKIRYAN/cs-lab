#include<iostream>

#include "Vehicle.h"



using namespace std;


void CreateVehicle(Vehicle& v, int w = 4, int d = 2)
{
	v.setNumWheels(w);
	v.setNumDoors(d);
}


Vehicle* testVehicle(Vehicle* pVehicle, const char* vehicleName)
{
	cout << vehicleName << "¡¯s range is: " << pVehicle->calculateRange() << endl;
	pVehicle->drive(150); //drive 150 km
	cout << vehicleName << "¡¯s energy left is: " << pVehicle->percentEnergyRemaining() << endl;
	cout << vehicleName << "¡¯s range is now: " << pVehicle->calculateRange() << endl;

	return pVehicle;
}


int main(int argc, char** argv)
{
	//50L of gas, 7.1 L/100km
	delete dynamic_cast<GasolineVehicle*>(testVehicle(new GasolineVehicle(50, 7.1), "Corolla"));

	//42 L of gas, 4.3 L/100km, 8.8kWh, 22 kWh/100km
	delete dynamic_cast<HybridVehicle*>(testVehicle(new HybridVehicle(42.0, 4.3, 8.8, 22.0), "Prius"));

	//75 kWh, 16 kWh/100km
	delete dynamic_cast<ElectricVehicle*>(testVehicle(new ElectricVehicle(75, 16), "Tesla 3"));

	return 0;
}