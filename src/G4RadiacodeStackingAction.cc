#include "G4RadiacodeStackingAction.hh"
#include "G4Track.hh"
#include "G4AntiNeutrinoE.hh"
#include "G4Electron.hh"
#include "G4Gamma.hh"
#include <cstdlib>
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/

G4RadiacodeStackingAction::G4RadiacodeStackingAction(){}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/

G4RadiacodeStackingAction::~G4RadiacodeStackingAction(){}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/

G4ClassificationOfNewTrack G4RadiacodeStackingAction::ClassifyNewTrack(const G4Track* track)
{

    // Do not anti-neutrino following the beta- decays 
    if (track->GetDefinition() == G4AntiNeutrinoE::AntiNeutrinoE())
    {
        return fKill;
    }

    return fUrgent;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/