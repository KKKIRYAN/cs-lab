#include "ElectricVehicle.h" 

float ElectricVehicle::calculateRange()
{
	return currentCharge * 100 / electricEffeciency;
}

float ElectricVehicle::percentEnergyRemaining()
{
	return currentCharge / maximumCharge * 100.0f;
}

void ElectricVehicle::drive(float km)
{
	currentCharge -= (km / 100) * electricEffeciency;
}
