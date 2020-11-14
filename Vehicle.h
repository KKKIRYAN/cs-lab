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

	Vehicle& operator--();

	friend ostream& operator<<(ostream&, const Vehicle& v);

	virtual float calculateRange() = 0;
	virtual float percentEnergyRemaining() = 0;
	virtual void drive(float km) = 0;

private:
	int numWheels;
	int numDoors;
};



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

	float calculateRange()
	{
		return currentCharge * 100 / electricEffeciency;
	}

	float percentEnergyRemaining()
	{
		return currentCharge / maximumCharge * 100.0f;
	}

	void drive(float km)
	{
		currentCharge -= (km / 100) * electricEffeciency;
	}

};


class GasolineVehicle : virtual public Vehicle
{
public:
	float currentGasoline;
	float maximumGasoline;
	float gasolineEfficiency;

	GasolineVehicle(float max_energy = 100, float efficiency = 100) {
		maximumGasoline = max_energy;
		currentGasoline = max_energy;
		gasolineEfficiency = efficiency;
	}

	float calculateRange()
	{
		return currentGasoline * 100 / gasolineEfficiency;
	}

	float percentEnergyRemaining()
	{
		return currentGasoline / maximumGasoline * 100.0f;
	}

	void drive(float km)
	{
		currentGasoline -= (km / 100) * gasolineEfficiency;
	}

};

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


	float calculateRange()
	{
		return (currentCharge * 100 / electricEffeciency)
			+ (currentGasoline * 100 / gasolineEfficiency);
	}

	float percentEnergyRemaining()
	{
		return ((currentCharge / maximumCharge * 100.0f) +
			(currentGasoline / maximumGasoline * 100.0f)) / 2;
	}

	void drive(float km)
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

};