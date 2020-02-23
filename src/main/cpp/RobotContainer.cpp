#include "RobotContainer.h"

enum class Pov : int {
    kRight = 90,
    kLeft = 270,
    kUp = 180,
    kDown = 0
};

RobotContainer::RobotContainer() : m_AutonomousCommand(&m_Drivetrain) {
    // Initialize all of your commands and subsystems here

    // Configure the button bindings
    ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
    // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
    // An example command will be run in autonomous
    return &m_AutonomousCommand;
}

// Quick drivetrain testing code :D
void RobotContainer::DrivetrainTest(double dt) {
  m_Drivetrain.Drive(dt, m_DriverJoystick);
}

void RobotContainer::PollInput() {
    // This works, but JoystickButton does not.
    if (m_OperatorJoystick.GetYButton() && !m_ExpelIntakeCommand.IsInitialized()) {
        m_ExpelIntakeCommand.Start();
    } else if (m_OperatorJoystick.GetYButtonReleased()) {
      m_ExpelIntakeCommand.Cancel();
    } 

    if (Pov::kRight == m_OperatorJoystick.GetPOV()) {
        m_ExtendIntakeCommand.Start()
    } else if (Pov::kLeft == m_OperatorJoystick.GetPOV()) {
        m_RetractIntakeCommand.Start()
    }
}
