#ifndef G4Radiacode_DETECTOR_CONSTRUCTION_H
#define G4Radiacode_DETECTOR_CONSTRUCTION_H 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4RadiacodeDetectorConstruction : public G4VUserDetectorConstruction
{
  public:

    G4RadiacodeDetectorConstruction();
    virtual ~G4RadiacodeDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
    virtual void ConstructSDandField();

};

#endif
