/*
 * IRArm.h
 *
 *  Created on: 2 feb. 2017
 *      Author: Dylan Vos
 */

#include <VictorSP.h>
#include <Servo.h>

#pragma once

namespace IR {

	class IRArm {
	public:
	
	
		IRArm(uint32_t ArmChannel, uint32_t ActuatorChannel);
	
		void StartArm();
		void StopArm();
		void BackwardsArm();		
		void AcuatorIn();
 		void AcuatorUit();
		
	protected:
		frc::VictorSP Arm;
 		frc::Servo Acuator;
	
	};
}

