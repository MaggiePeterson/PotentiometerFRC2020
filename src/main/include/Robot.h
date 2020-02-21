/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <AnalogPot.h>
#include <frc/Joystick.h>

class Robot : public frc::TimedRobot {
 public:
  //frc::AnalogPotentiometer pot {0, 270, 135};
  //frc::AnalogPotentiometer::AnalogPotentiometer (0, 270, 135)//intializes on port 0, 270 is full degree of motion, 135 degrees is the starting point 
  //int bottom_marker;
  //int horizontal_marker;  
  //int horizontal_marker_degree;

  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  //double get_arm_position();
  //void in_range(double current_degree);

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  frc::Joystick* joystickContr;
  frc::JoystickButton* toggle;
  AnalogPot aPot;

};
