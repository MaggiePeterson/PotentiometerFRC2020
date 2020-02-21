/*----------------------------------------------------------------------------*/
/* Copyright (c) 2016-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
 
/* #pragma once
 
#include <memory>
 
#include "frc/AnalogInput.h"
#include "frc/ErrorBase.h"
#include "frc/interfaces/Potentiometer.h"
#include "frc/smartdashboard/Sendable.h"
#include "frc/smartdashboard/SendableHelper.h"

namespace frc {
 
class SendableBuilder;
 
class AnalogPotentiometer : public ErrorBase,
                            public Potentiometer,
                            public Sendable,
                            public SendableHelper<AnalogPotentiometer> {
 public:
  explicit AnalogPotentiometer(int channel, double fullRange = 1.0,
                               double offset = 0.0);
 
  explicit AnalogPotentiometer(AnalogInput* input, double fullRange = 1.0,
                               double offset = 0.0);
 
  explicit AnalogPotentiometer(std::shared_ptr<AnalogInput> input,
                               double fullRange = 1.0, double offset = 0.0);
 
  ~AnalogPotentiometer() override = default;
 
  AnalogPotentiometer(AnalogPotentiometer&&) = default;
  AnalogPotentiometer& operator=(AnalogPotentiometer&&) = default;
 
  double Get() const override;
 
  double PIDGet() override;
 
  void InitSendable(SendableBuilder& builder) override;
 
 private:
  std::shared_ptr<AnalogInput> m_analog_input;
  double m_fullRange, m_offset;
};
 
}  // namespace frc */ 

#include <string>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/buttons/JoystickButton.h>
#include <frc/AnalogPotentiometer.h>

//after the potentiometer is fixed, need to align the robot arm against the hardstop to save the value as bottom_marker
//then need to find the horizontal marker which is the angle of the robot arm when the hanger is level (parallel to the ground)
#define bottomMarker (0.2)
#define horizontalMarker (0.4)
#define horizontalMarkerDeg (horizontalMarker * 270)

class AnalogPot {
  frc::AnalogPotentiometer pot {0, 270, 0};
  public:
    AnalogPot();
    double get_arm_position();
    void in_range(double current_degree);
    //bool in_range();
};