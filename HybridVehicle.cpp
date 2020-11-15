#include "HybridVehicle.h"

float HybridVehicle::calculateRange()
{
	return (currentCharge * 100 / electricEffeciency)
		+ (currentGasoline * 100 / gasolineEfficiency);
}

float HybridVehicle::percentEnergyRemaining()
{
	return ((currentCharge / maximumCharge * 100.0f) +
		(currentGasoline / maximumGasoline * 100.0f)) / 2;
}

void HybridVehicle::drive(float km)
{
	float electric_km = currentCharge / electricEffeciency * 100;
	if (electric_km < km) {
		currentCharge = 0;
		km = km - electric_km;
	}
	else {
		currentCharge = currentCharge - (km / 100) * electricEffeciency;
		return;
	}

	float gasoline_km = currentGasoline / gasolineEfficiency * 100;
	if (gasoline_km < km) {
		currentGasoline = 0;
		cout << "Your car is out of energy!" << endl;
	}
	else {
		currentGasoline = currentGasoline - (km / 100) * gasolineEfficiency;
		return;
	}
}
