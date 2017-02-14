/*
 * IRArm.h
 *
 *  Created on: 2 feb. 2017
 *      Author: Dylan Vos
 */

#pragma once
#include <Servo.h>

class IRArm {
public:
	
	
	IRArm(unit32_t ArmChannel);
	
	void StartArm();
	void AcuatorIn();
	void AcuatorUit();

	protected:
	frc::VictorSP Arm;
	
	protected:
	frc::Servo Acuator;

	
};

