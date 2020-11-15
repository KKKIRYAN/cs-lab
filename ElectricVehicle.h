#include "Vehicle.h"

#ifndef ELECTRIC_VEHICLE_H
#define ELECTRIC_VEHICLE_H

class ElectricVehicle : virtual public Vehicle
{
public:
	float currentCharge;
	float maximumCharge;
	float electricEffeciency;

	ElectricVehicle(float max_energy = 100, float efficiency = 100) {
		currentCharge = max_energy;
		maximumCharge = max_energy;
		electricEffeciency = efficiency;
	}

	float calculateRange();

	float percentEnergyRemaining();

	void drive(float km);
};

#endif
