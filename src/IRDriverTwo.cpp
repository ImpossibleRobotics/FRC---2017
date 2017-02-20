/*
 * IRDriverTwo.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: Dylan Vos
 */

#include <IRDriverTwo.h>

namespace IR {

IRDriverTwo::IRDriverTwo(IRJoystick *_joystick, IRArm *_irArm, IRLift *_irLift) {
	joystick = _joystick;
	irArm = _irArm;
	irLift = _irLift;
}

IRDriverTwo::~IRDriverTwo() {
	// TODO Auto-generated destructor stub
}

void IRDriverTwo::Run(){
	if(joystick->GetRawButton(0)) irArm->ActuatorIn(); // A-Button State, Defines if button is pressed
	if(joystick->GetRawButton(2)) irArm->ActuatorUit(); // X-Button State, ""

	if(joystick->GetRawButton(4)) irArm->StartArm(); // Left_Bumper-Button State, Defines if button is pressed
	if(joystick->GetRawButton(1)) irArm->StopArm(); // B-Button State, ""
	if(joystick->GetRawButton(5)) irArm->BackwardsArm(); // Right_Bumper-Button State, ""

	if(joystick->GetRawButton(3)) irLift->Lift(); // Y-Button State, Defines if button is pressed
	if(joystick->GetRawButton(1)) irLift->StopLift(); // B-Button State, ""

	frc::Wait(0.005);
}

} /* namespace IR */
