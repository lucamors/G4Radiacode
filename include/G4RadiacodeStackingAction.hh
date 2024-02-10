#ifndef G4Radiacode_STACKING_ACTION_H
#define G4Radiacode_STACKING_ACTION_H

#include "G4UserStackingAction.hh"
#include "globals.hh"

class G4RadiacodeStackingAction : public G4UserStackingAction
{
   public:

      G4RadiacodeStackingAction();
      virtual ~G4RadiacodeStackingAction();

      virtual G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track*);

};

#endif