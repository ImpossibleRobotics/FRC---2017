/*
 * 2017
 * */
#include <iostream>
#include <memory>
#include <string>

#include <HumanInterfaceDevices/IRJoystick.h>
#include <RobotDrive/IRCANRobotDrive.h>

#include <Joystick.h>
#include <SampleRobot.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Timer.h>

#include <IRArm.h>
#include <IRLift.h>
#include <IRDriverOne.h>
#include <IRDriverTwo.h>

#include <../drivers/imu/ADIS16448_IMU.h>

class Robot: public frc::SampleRobot {
	//							  FL, RL, FR, RR
	IR::IRCANRobotDrive myDrive	 {2,  3,  1,  0, IR::Mecanum};
	IR::IRJoystick 		joystick {0},
						gamePad{1};
	IR::IRArm			irArm {9,9};	//poorten moeten woorden defenieerd. Nadat elektronika in orde is.
	IR::IRLift 			irLift {9,9};

	frc::SendableChooser<std::string> chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";

	IR::IRDriverOne driverOneTask {&joystick, &myDrive};
	IR::IRDriverTwo driverTwoTask {&gamePad, &irArm, &irLift};

//	ADIS16448_IMU *imu;

public:
	Robot() {
//		imu = new ADIS16448_IMU;
	}
	void RobotInit() {
		chooser.AddDefault(autoNameDefault, autoNameDefault);
		chooser.AddObject(autoNameCustom, autoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &chooser);
	}

	/*
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as well.
	 */
	void Autonomous() {
		auto autoSelected = chooser.GetSelected();
		// std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;
	}

	/*
	 * Runs the motors with arcade steering.
	 */
	void OperatorControl() override {
		while (IsOperatorControl() && IsEnabled()) {
			if(!driverOneTask.isEnabled()) driverOneTask.Start();
			if(!driverTwoTask.isEnabled()) driverTwoTask.Start();

//			SmartDashboard::PutData("IMU", imu);

			SmartDashboard::PutNumber("Joy-Y", joystick.GetY());
			SmartDashboard::PutNumber("Joy-Y-DeadZoned", joystick.GetYDeadZoned());

			SmartDashboard::PutNumber("Joy-X", joystick.GetX());
			SmartDashboard::PutNumber("Joy-X-DeadZoned", joystick.GetXDeadZoned());

			SmartDashboard::PutNumber("Joy-Z", joystick.GetZ());
			SmartDashboard::PutNumber("Joy-Z-DeadZoned", joystick.GetZDeadZoned());

			SmartDashboard::PutNumber("Joy-Throttle", joystick.GetThrottle());
			SmartDashboard::PutNumber("Joy-Throttle-Leveled", joystick.GetLeveledThrottle());

			// wait for a motor update time
			frc::Wait(0.005);
		}
		driverOneTask.Terminate();
		driverTwoTask.Terminate();
	}

	/*
	 * Runs during test mode
	 */
	void Test() override {

	}

private:
};

START_ROBOT_CLASS(Robot)
