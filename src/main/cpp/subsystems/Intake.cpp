#include "subsystems/Intake.h"

#include <ctre/phoenix/motorcontrol/ControlMode.h>

#define kCornerMotorAdjust 1

Intake::Intake () {}

void Intake::Periodic () {}

void Intake::SetSpeed (double intakeSpeed) {
    m_IntakeMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, intakeSpeed);
}

void Intake::SetConveyorSpeed (double conveyorSpeed) {
    m_ConveyorCornerMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, conveyorSpeed*kCornerMotorAdjust);
    m_ConveyorAdvanceMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, conveyorSpeed);
}

void Intake::IntakeStart () {
    SetSpeed(1.0);
    SetConveyorSpeed(1);
}

void Intake::IntakeStop () {
    SetSpeed(0.0);
    SetConveyorSpeed(0);
}

void Intake::IntakeReverse () {
    SetSpeed(-0.5);
    SetConveyorSpeed(0);
}
