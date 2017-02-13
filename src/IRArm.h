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
	
	protected:
	frc::VictorSP Arm;
	
};


class IRAcuator{
public:
	IRAcuator(uint32_AcuatorChannel);

	void AcuatorIn();
	void AcuatorUit();

protected:
	frc::Servo Acuator;

};
