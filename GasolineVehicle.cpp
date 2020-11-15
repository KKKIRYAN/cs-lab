#include "GasolineVehicle.h"

float GasolineVehicle::calculateRange()
{
	return currentGasoline * 100 / gasolineEfficiency;
}

float GasolineVehicle::percentEnergyRemaining()
{
	return currentGasoline / maximumGasoline * 100.0f;
}

void GasolineVehicle::drive(float km)
{
	currentGasoline -= (km / 100) * gasolineEfficiency;
}
