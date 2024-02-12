// User Defined Classes
#include "G4RadiacodeDetectorConstruction.hh"
#include "G4RadiacodeSensitiveDetector.hh"

// Geometry Related Libraries
#include "G4SDManager.hh"
#include "G4NistManager.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"

// CGS Geometry Classes
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"

// Visualization Libraries
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

G4RadiacodeDetectorConstruction::G4RadiacodeDetectorConstruction()
: G4VUserDetectorConstruction(){}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

G4RadiacodeDetectorConstruction::~G4RadiacodeDetectorConstruction(){}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

G4VPhysicalVolume* G4RadiacodeDetectorConstruction::Construct()
{

  /////////////////////////////////////////////////////////////////////////////
  // Materials Definition
  /////////////////////////////////////////////////////////////////////////////
  G4NistManager * nist = G4NistManager::Instance();

  G4Material * material_Air     = nist->FindOrBuildMaterial("G4_AIR");
  G4Material * material_CsI     = nist->FindOrBuildMaterial("G4_CESIUM_IODIDE");
  G4Material * material_Plexi   = nist->FindOrBuildMaterial("G4_PLEXIGLASS");
  
  G4Element * elC  = new G4Element("Carbon", "C", 6, 12.011*g/mole);
  G4Element * elH  = new G4Element("Hydrogen", "H", 1, 1.008*g/mole);
  G4Element * elO  = new G4Element("Oxygen", "O", 8, 15.999*g/mole);

  G4double density = 1.25 * g / cm3;
  G4int nComponents = 3;
  G4Material * materialPLA = new G4Material("PLA", density, nComponents);
  materialPLA->AddElement(elC, 3);
  materialPLA->AddElement(elH, 4);
  materialPLA->AddElement(elO, 2);

  /////////////////////////////////////////////////////////////////////////////
  // World Volume
  /////////////////////////////////////////////////////////////////////////////

  G4double world_half_Z  = 50*cm;
  G4double world_half_XY = 50*cm;

  G4Box * solid_World = new G4Box("solid_World", world_half_XY, world_half_XY, world_half_Z);

  G4LogicalVolume* logical_World = new G4LogicalVolume(solid_World,
                                                       material_Air,
                                                       "logical_World",
                                                       0,
                                                       0,
                                                       0,
                                                       true);

  G4VPhysicalVolume * physical_World = new G4PVPlacement(0,
                                                        G4ThreeVector(),
                                                        logical_World,
                                                        "physicalWorld",
                                                        0,
                                                        false,
                                                        0,
                                                        true);


  /////////////////////////////////////////////////////////////////////////////
  // Crystal Enclosure
  /////////////////////////////////////////////////////////////////////////////
  G4double enclosure_half_dimension = 0.8*cm;

  G4Tubs * solid_enclosure = new G4Tubs("solid_crystal", 0, enclosure_half_dimension, 0.6*cm, 0*deg, 2*M_PI*rad);

  G4LogicalVolume* logical_enclosure = new G4LogicalVolume(solid_enclosure,
                                                         materialPLA,
                                                         "logical_enclosure",
                                                         0,
                                                         0,
                                                         0,
                                                         true);

  new G4PVPlacement(0,
                    G4ThreeVector(),
                    logical_enclosure,
                    "physical_enclosure",
                    logical_World,
                    false,
                    0,
                    true);


  /////////////////////////////////////////////////////////////////////////////
  // Air spacer
  /////////////////////////////////////////////////////////////////////////////
  G4double enclosure_air_spacer = 0.72*cm;

  G4Tubs * solid_enclosure_spacer = new G4Tubs("solid_crystal", 0, enclosure_air_spacer,0.51*cm, 0, 2*M_PI*rad);

  G4LogicalVolume* logical_enclosure_air = new G4LogicalVolume(solid_enclosure_spacer,
                                                           material_Air,
                                                           "logical_enclosure_air",
                                                           0,
                                                           0,
                                                           0,
                                                           true);

  new G4PVPlacement(0,
                    G4ThreeVector(),
                    logical_enclosure_air,
                    "physical_enclosure",
                    logical_enclosure,
                    false,
                    0,
                    true);

  /////////////////////////////////////////////////////////////////////////////
  // Radiacode CsI(Tl) crystal
  /////////////////////////////////////////////////////////////////////////////
  G4double crystal_half_dimension = 0.5*cm;
  

  G4Box * solid_crystal = new G4Box("solid_crystal", crystal_half_dimension, crystal_half_dimension, crystal_half_dimension);

  G4LogicalVolume* logical_crystal = new G4LogicalVolume(solid_crystal,
                                                          material_CsI,
                                                          "logical_crystal",
                                                          0,
                                                          0,
                                                          0,
                                                          true);

  new G4PVPlacement(0,
                    G4ThreeVector(),
                    logical_crystal,
                    "physical_crystal",
                    logical_enclosure_air,
                    false,
                    0,
                    true);


  /////////////////////////////////////////////////////////////////////////////
  // Source Enclosure
  /////////////////////////////////////////////////////////////////////////////
  G4double source_enclosure_radius = 1*mm;

  G4Sphere * solid_source_enclosure = new G4Sphere("solid_source_enclosure",
                                                   0,
                                                   source_enclosure_radius,
                                                   0,
                                                   2*M_PI*rad,
                                                   0,
                                                   M_PI*rad
                                                  );

  G4LogicalVolume* logical_source_enclosure = new G4LogicalVolume(solid_source_enclosure,
                                                         material_Plexi,
                                                         "logical_source_enclosure",
                                                         0,
                                                         0,
                                                         0,
                                                         true);

  new G4PVPlacement(0,
                    G4ThreeVector(0,0,-2*cm),
                    logical_source_enclosure,
                    "physical_enclosure",
                    logical_World,
                    false,
                    0,
                    true);
  /////////////////////////////////////////////////////////////////////////////
  // Visualization Attributes
  /////////////////////////////////////////////////////////////////////////////

  logical_World->SetVisAttributes(G4VisAttributes::GetInvisible());
  logical_enclosure->SetVisAttributes(G4VisAttributes(G4Colour(80.0/255.0, 80.0/255,80.0/255,0.7)));
  logical_enclosure_air->SetVisAttributes(G4VisAttributes(G4Colour(250.0/255.0, 250.0/255,250.0/255,0.1)));
  logical_crystal->SetVisAttributes(G4VisAttributes(G4Colour(227.0/255.0, 210.0/255,213.0/255,0.7)));

  return physical_World;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void G4RadiacodeDetectorConstruction::ConstructSDandField()
{
  G4RadiacodeSensitiveDetector * sd = new G4RadiacodeSensitiveDetector("Radiacode SD","RadiacodeHitsCollection");

  G4SDManager::GetSDMpointer()->AddNewDetector(sd);
  SetSensitiveDetector("logical_crystal", sd);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
