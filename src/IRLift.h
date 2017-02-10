/*
 * IRLift.h
*/

#pragma once

#include <VictorSP.h>

class IRLift {
public:
	IRLift.h::IRLift(uint32_t Lift1Channel, uint32_t Lift2Channel);

	void Lift();
	void StopLift();
	

protected:
	frc::VictorSP Lift1, Lift2;

};
