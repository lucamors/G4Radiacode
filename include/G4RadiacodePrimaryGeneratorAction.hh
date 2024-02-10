#ifndef G4Radiacode_PRIMARY_GENERATOR_ACTION_H
#define G4Radiacode_PRIMARY_GENERATOR_ACTION_H 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4GeneralParticleSource.hh"

class G4RadiacodePrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:

    G4RadiacodePrimaryGeneratorAction();
    ~G4RadiacodePrimaryGeneratorAction();
    void GeneratePrimaries(G4Event* anEvent);

private:
    G4GeneralParticleSource* fParticleGPS;
};

#endif
