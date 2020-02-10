/*----------------------------------------------------------------------------*/
/* Copyright (c) 2016-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
 
#pragma once
 
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
 
}  // namespace frc