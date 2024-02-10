#ifndef G4Radiacode_EVENT_ACTION_H
#define G4Radiacode_EVENT_ACTION_H 1

#include "G4UserEventAction.hh"
#include "globals.hh"

#include "G4RadiacodeHit.hh"

class G4RadiacodeEventAction : public G4UserEventAction
{
  public:

    G4RadiacodeEventAction();
    virtual ~G4RadiacodeEventAction();

    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);

  private:

    G4RadiacodeHitsCollection* GetHitsCollection(G4int hcID, const G4Event* event) const;
    G4int fHCID;

};

#endif
