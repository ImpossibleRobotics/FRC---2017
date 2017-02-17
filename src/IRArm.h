/*
 * IRArm.h
 *
 *  Created on: 2 feb. 2017
 *      Author: Dylan Vos
 */

#include<VictorSP.h>

#pragma once

namespace IR {

	class IRArm {
	public:
	
	
		IRArm(uint32_t ArmChannel);
	
		void StartArm();
		void StopArm();
		void BackwardsArm();
	
	protected:
		frc::VictorSP Arm;
	
	};
}

