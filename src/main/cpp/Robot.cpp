/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

#include "frc/DriverStation.h"

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  
  //aPot = new AnalogPot();
  AnalogPot aPot;
  joystickContr = new frc::Joystick(0);
  toggle = new frc::JoystickButton(joystickContr, 1); //the one you move in order to move the wheel along the hanger; if it moves, want to check the balance

  
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  m_autoSelected = frc::SmartDashboard::GetString("Auto Selector",
       kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

/* double Robot::get_arm_position() { 
    double incoming_value = pot.Get();
    double degree_value = (incoming_value - horizontal_marker)*(1/270);
    return (degree_value);
  };

void Robot::in_range(double current_degree){
    if (((current_degree - horizontal_marker_degree) >= -8) && ((current_degree - horizontal_marker_degree) <= 8)) {
      frc::SmartDashboard::PutNumber("In Range: ", current_degree);
    }
    else {
      frc::SmartDashboard::PutNumber("Out of Range by: ", current_degree);
    };
  }; */

void Robot::TeleopPeriodic() {
  //bottom_marker = 0.2;
  //horizontal_marker = 0.4;
  //horizontal_marker_degree = horizontal_marker * 270;
  //frc::SmartDashboard::PutNumber("Horizontal Marker Degree", horizontal_marker_degree);
  //in_range(get_arm_position());
  if (toggle->Get()) {
    aPot.in_range(aPot.get_arm_position());
  }
};

void Robot::TestPeriodic() {
  //frc::SmartDashboard::PutData("Hello World");
  
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); };
#endif