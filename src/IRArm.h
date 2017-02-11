/*
 * IRArm.h
 *
 *  Created on: 2 feb. 2017
 *      Author: Dylan Vos
 */

#pragma once

class IRArm {
public:
	
	
	IRArm(unit32_t ArmChannel);
	
	void StartArm();
	
	protected:
	frc::VictorSP Arm;
	
};

