#ifndef HYBRID_VEHICLE_H
#define HYBRID_VEHICLE_H

#include "ElectricVehicle.h" 
#include "GasolineVehicle.h"

class HybridVehicle : public ElectricVehicle, public GasolineVehicle
{
public:
	HybridVehicle(float maximum_gasoline, float gasoline_efficiency, float maximum_charge, float electric_effeciency)
	{
		currentGasoline = maximum_gasoline;
		maximumGasoline = maximum_gasoline;
		gasolineEfficiency = gasoline_efficiency;
		currentCharge = maximum_charge;
		maximumCharge = maximum_charge;
		electricEffeciency = electric_effeciency;
	}

	float calculateRange();

	float percentEnergyRemaining();

	void drive(float km);
};

#endif
