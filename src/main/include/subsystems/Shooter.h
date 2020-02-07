#pragma once

#include "Constants.h"

#include <frc/SpeedControllerGroup.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>
#include <units/units.h>

class Shooter : public frc2::SubsystemBase {
    public:
        Shooter();
        void Periodic() override;

        void SetShooterMotorSpeeds(double leftSpeed, double rightSpeed);

        void SetTurretSpeed(units::angular_velocity::radians_per_second_t speed);

    private:
        rev::CANSparkMax m_ShooterMotor1 {kShooterMotor1, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANPIDController m_ShooterMotor1PID {m_ShooterMotor1};
        rev::CANEncoder m_ShooterMotor1Encoder {m_ShooterMotor1};
        
        rev::CANSparkMax m_ShooterMotor2 {kShooterMotor2, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANPIDController m_ShooterMotor2PID {m_ShooterMotor2};
        rev::CANEncoder m_ShooterMotor2Encoder {m_ShooterMotor2};

        ctre::phoenix::motorcontrol::can::TalonSRX m_TurretMotor {kTurretMotor};
};