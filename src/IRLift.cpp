/*
 * IRLift.cpp
 */

#include <IRLift.h>

using namespace IR;

IRLift::IRLift(uint32_t Lift1Channel, uint32_t Lift2Channel) :
	Lift1(Lift1Channel),
	Lift2(Lift2Channel)
{
	
}

void IRLift::Lift()
{
	Lift1.Set(1);
	Lift2.Set(1);
}

void IRLift::StopLift()
{
	Lift1.Set(0);
	Lift2.Set(0);
}
