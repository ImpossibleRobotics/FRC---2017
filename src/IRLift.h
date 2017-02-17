/*
 * IRLift.h
*/

#pragma once

#include <VictorSP.h>

namespace IR {

	class IRLift {
	public:
		IRLift(uint32_t Lift1Channel, uint32_t Lift2Channel);

		void Lift();
		void StopLift();
	

	protected:
		frc::VictorSP Lift1, Lift2;

	};

}
