#ifndef G4Radiacode_DETECTOR_CONSTRUCTION_H
#define G4Radiacode_DETECTOR_CONSTRUCTION_H 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"


class G4Box;
class G4Sphere;
class G4Tubs;
class G4Element;
class G4Material;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4RadiacodeSensitiveDetector;


class G4RadiacodeDetectorConstruction : public G4VUserDetectorConstruction
{
  public:

    G4RadiacodeDetectorConstruction();
    virtual ~G4RadiacodeDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
    virtual void ConstructSDandField();

  private:

    G4Element* elC;
    G4Element* elH;
    G4Element* elO;

    G4Material* material_Air;
    G4Material* material_CsI;
    G4Material* material_Plexi;
    G4Material* material_Wood;
    G4Material* material_PLA;

    G4Box*  solid_World;
    G4Box * solid_crystal;
    G4Box * table_solid;
    G4Tubs* solid_enclosure;
    G4Tubs* solid_enclosure_spacer;
    G4Sphere * solid_source_enclosure;

    G4LogicalVolume* logical_World;
    G4LogicalVolume* logical_crystal;
    G4LogicalVolume* logical_table;
    G4LogicalVolume* logical_source_enclosure;
    G4LogicalVolume* logical_enclosure;
    G4LogicalVolume* logical_enclosure_air;

    G4VPhysicalVolume* physical_World;
    G4VPhysicalVolume* physical_crystal;
    G4VPhysicalVolume* physical_table;
    G4VPhysicalVolume* physical_source_enclosure;
    G4VPhysicalVolume* physical_enclosure;
    G4VPhysicalVolume* physical_enclosure_air;

    G4RadiacodeSensitiveDetector * sd;
};

#endif
