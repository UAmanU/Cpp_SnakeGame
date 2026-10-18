#include "include/programm_launcher.h" //including the ProgrammLauncher class to launch the code.

/*main.cpp - is a file where int main() func is realised.
it creates a smart pointer to ProgrammLauncher and calls ProgrammLauncher::prepare() and ProgrammLauncher::launch_programm() methods*/

int main()
{

    std::unique_ptr<ProgrammLauncher> programm_launcher = std::make_unique<ProgrammLauncher>(); // created a smart pointer to Programm_launcher
    programm_launcher->prepare();                                                               // calling the method for InitWindow() SetUp and game SetUp
    programm_launcher->launch_programm();                                                       // calling the method for programm loop's running.

    return 0;
}
