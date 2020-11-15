#include "Vehicle.h"

#ifndef GASOLINE_VEHICLE_H
#define GASOLINE_VEHICLE_H

class GasolineVehicle : virtual public Vehicle
{
public:
	float currentGasoline;
	float maximumGasoline;
	float gasolineEfficiency;

	GasolineVehicle(float max_energy = 100, float efficiency = 100)
	{
		maximumGasoline = max_energy;
		currentGasoline = max_energy;
		gasolineEfficiency = efficiency;
	}

	float calculateRange();

	float percentEnergyRemaining();

	void drive(float km);
};

#endif
