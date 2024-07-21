/*
 Radiacode Geant4 Model
 ------------------------
 Radiacode 103
*/

// Geant4 core libs
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include "Randomize.hh"

#include "QGSP_BIC_HP.hh"
// User defined classes
#include "G4RadiacodeDetectorConstruction.hh"
#include "G4RadiacodePhysicsList.hh"
#include "G4RadiacodePrimaryGeneratorAction.hh"
#include "G4RadiacodeRunAction.hh"
#include "G4RadiacodeStackingAction.hh"
#include "G4RadiacodeEventAction.hh"

// STL libs
#include <memory>
#include <random>
#include <ctime>
#include <chrono>

int main(int argc, char** argv)
{

    G4UIExecutive * ui = 0;
    if(argc == 1)
    {
        ui = new G4UIExecutive(argc, argv);
    }

    // Choose the random engine
    G4Random::setTheEngine(new CLHEP::RanecuEngine);
    
    // Initialize SEED using current time since epoch
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Set HepRandom with time dependent seed --> Needed for Cloud Parallelization
    CLHEP::HepRandom::setTheSeed(seed);
    G4Random::setTheSeed(seed);

    // Construct the run manager
    G4RunManager * runManager = new G4RunManager;

    // Set Mandatory initialization classes
    // ---------------------------------------------------------------------------

    G4RadiacodeDetectorConstruction * det = new G4RadiacodeDetectorConstruction();
    runManager->SetUserInitialization(det);

    G4RadiacodePhysicsList  * phys = new G4RadiacodePhysicsList();
    runManager->SetUserInitialization(phys);

    // Set action classes
    // ---------------------------------------------------------------------------
    G4RadiacodePrimaryGeneratorAction * gen = new G4RadiacodePrimaryGeneratorAction();
    runManager->SetUserAction(gen);

    G4RadiacodeRunAction * run = new G4RadiacodeRunAction();
    runManager->SetUserAction(run);

    G4RadiacodeEventAction * event = new G4RadiacodeEventAction();
    runManager->SetUserAction(event);

    G4RadiacodeStackingAction * stack = new G4RadiacodeStackingAction();
    runManager->SetUserAction(stack);

    // Initialize Geant4 Kernel
    runManager->Initialize();

    // Initialize visualization
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();

    // get the pointer to the User Interface Manager
    G4UImanager * uiManager = G4UImanager::GetUIpointer();

    if(!ui)
    {
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        uiManager->ApplyCommand(command+fileName);
    }
    else
    {

        uiManager->ApplyCommand("/control/execute macro/vis/initialize_visualization.mac");
        ui->SessionStart();
        delete ui;
    }

    // Terminate application
    // All user action and initialization classes are freed by the runManager
    // so they should not be deleted in the main() program
    delete visManager;
    delete runManager;
    
    return 0;
}
