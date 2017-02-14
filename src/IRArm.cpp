/*
 * IRArm.cpp
 *
 *  Created on: 2 feb. 2017
 *      Author: Dylan Vos
 */

#include <IRArm.h>


	IRArm::IRArm(uint32_t ArmChannel) :
	
	Arm(ArmChannel)
Void IRArm::StartArm()
{
	Arm.set(1);

}
	Void IRArm::StopArm()
	{
	Arm.set(0);	
	}

Void IRArm::BackwardsArm()
{

	Arm.set(-1);
	
	
}


void IRAcuator::AcuatorIn()
{
	Acuator.Set(0);
}

void IRAcuator::AcuatorUit()
{
	Acuator.Set(1)
}

