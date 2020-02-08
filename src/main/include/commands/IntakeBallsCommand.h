#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Conveyor.h"
#include "subsystems/Intake.h"

class IntakeBallsCommand : public frc2::CommandHelper<frc2::CommandBase, IntakeBallsCommand> {
    public:
        IntakeBallsCommand(Intake* intake);

        void Initialize();
        void Execute();
        void End();
        bool IsFinished();

    private:
        Intake* m_Intake;
};