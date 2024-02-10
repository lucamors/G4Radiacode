#ifndef G4Radiacode_PHYSICS_LIST
#define G4Radiacode_PHYSICS_LIST 1

#include "G4VModularPhysicsList.hh"


class G4RadiacodePhysicsList : public G4VModularPhysicsList
{
  public:

    G4RadiacodePhysicsList();
    virtual ~G4RadiacodePhysicsList();
    virtual void SetCuts();

};

#endif
