#include "G4RadiacodeSensitiveDetector.hh"
#include "G4Step.hh"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include <string>

G4RadiacodeSensitiveDetector::G4RadiacodeSensitiveDetector()
: G4VSensitiveDetector("det"), fHitsCollection(nullptr){}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

G4RadiacodeSensitiveDetector::G4RadiacodeSensitiveDetector(const G4String& name, const G4String& HC_name)
: G4VSensitiveDetector(name), fHitsCollection(nullptr)
{
  collectionName.insert(HC_name);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

G4RadiacodeSensitiveDetector::~G4RadiacodeSensitiveDetector()
{
	// fHitsCollection will be freed by the G4RunManager
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void G4RadiacodeSensitiveDetector::Initialize(G4HCofThisEvent* hitCollectionOfEvent)
{
  // Create an Hit Collection
  fHitsCollection = new G4RadiacodeHitsCollection(SensitiveDetectorName, collectionName[0]);

  auto HCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);

  hitCollectionOfEvent->AddHitsCollection(HCID, fHitsCollection);

  return ;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

G4bool G4RadiacodeSensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory* history)
{

	// Create an hit object
	G4RadiacodeHit * hit = new G4RadiacodeHit(); 
	G4double edep = step->GetTotalEnergyDeposit()/CLHEP::keV;

	std::string pname = step->GetTrack()->GetCreatorModelName();

	if(edep > 0)
	{
		hit->SetEdep(edep);
		hit->SetProcessName(pname);
		fHitsCollection->insert(hit);
	}

	return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void G4RadiacodeSensitiveDetector::EndOfEvent(G4HCofThisEvent*)
{
  return ;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
