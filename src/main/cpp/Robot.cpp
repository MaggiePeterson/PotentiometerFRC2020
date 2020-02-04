/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  //int small_arm = 15;
  //int pot_height = 9;
  //int sWheel_to_Under_Pot = 12
  //int pot_to_one_by_one = 0.5
  //int bwheel_radius = 2;
  //int normal_distance = sWheel_to_Under_Pot + pot_to_one_by_one + bwheel_radius
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
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
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

void Robot::TeleopPeriodic() {
  //after the potentiometer is fixed, need to align the robot arm against the hardstop to save the value as bottom_marker
  //then need to find the horizontal marker which is the angle of the robot arm when the hanger is level (parallel to the ground)
  bottom_marker = 0.2;
  horizontal_marker = 0.4;
  horizontal_marker_degree = horizontal_marker * 270;
  
  void get_arm_position(){
    double incoming_value = pot.get;
    degree_value = (incoming_value - horizontal_marker)*(1/270);
    return (degree_value);
  }
  void in_range(current_degree){
    if (((current_degree - horizontal_marker_degree) >= -8) && ((current_degree - horizontal_marker_degree) <= 8)) {
      frc::SmartDashboard::PutString("In Range:", current_degree);
    }
    else {
      frc::SmartDashboard::PutString("Out of Range by:", current_degree);
    }
  }

}

void Robot::TestPeriodic() {
  in_range(get_arm_position());
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
