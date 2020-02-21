#include "AnalogPot.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "frc/DriverStation.h"
#include <string>
#include <frc/AnalogPotentiometer.h>

AnalogPot::AnalogPot()
{
    //frc::AnalogPotentiometer pot {0, 270, 0};
} 

double AnalogPot::get_arm_position() 
{ 
    //frc::AnalogPotentiometer pot {0, 270, 0};
    double incoming_value = pot.Get();
    double degree_value = (incoming_value - horizontalMarker)*(1/270);
    return (degree_value);
}

void AnalogPot::in_range(double current_degree)
{
    if (((current_degree - horizontalMarkerDeg) >= -8) && ((current_degree - horizontalMarkerDeg) <= 8)) {
      frc::SmartDashboard::PutNumber("In Range: ", current_degree);
    }
    else {
      frc::SmartDashboard::PutNumber("Out of Range by: ", current_degree);
    }
}