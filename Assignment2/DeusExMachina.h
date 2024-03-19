#pragma once

#include "Vehicle.h"

#define MAX_NUM_OF_VEHICLE1 9

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		Vehicle* GetVehicle(unsigned int i) const;
		const Vehicle* GetFurthestTravelled() const;
		
	private:
		~DeusExMachina();
		DeusExMachina();

		static bool mbInstlanceExist;
		static DeusExMachina* mInstance;
		static unsigned int mNumVehicle;
		static bool mbRenew;

		Vehicle* mVehicle[10];
	};
}