#include "G4RadiacodePrimaryGeneratorAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4RadiacodePrimaryGeneratorAction::G4RadiacodePrimaryGeneratorAction()
{
    fParticleGPS = new G4GeneralParticleSource();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4RadiacodePrimaryGeneratorAction::~G4RadiacodePrimaryGeneratorAction()
{
    delete fParticleGPS;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void G4RadiacodePrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
    fParticleGPS->GeneratePrimaryVertex(anEvent);
}
