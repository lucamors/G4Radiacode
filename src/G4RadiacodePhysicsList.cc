#include "G4RadiacodePhysicsList.hh"
#include "G4DecayPhysics.hh"
// #include "G4EmStandardPhysics_option2.hh"
// #include "G4EmStandardPhysics_option3.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4HadronicParameters.hh"
#include "G4StepLimiterPhysics.hh"

G4RadiacodePhysicsList::G4RadiacodePhysicsList() : G4VModularPhysicsList()
{

  // Decay Physics
  ReplacePhysics(new G4DecayPhysics());
  ReplacePhysics(new G4RadioactiveDecayPhysics());
  // EM 3
  RegisterPhysics(new G4EmStandardPhysics_option3());

   G4HadronicParameters::Instance()->SetTimeThresholdForRadioactiveDecay( 5.0e+3*CLHEP::year );

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

G4RadiacodePhysicsList::~G4RadiacodePhysicsList(){}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void G4RadiacodePhysicsList::SetCuts()
{
  G4VUserPhysicsList::SetCuts();

  return ;
}
