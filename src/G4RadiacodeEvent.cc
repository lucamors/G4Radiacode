#include "G4RadiacodeEventAction.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "Analysis.hh"

G4RadiacodeEventAction::G4RadiacodeEventAction() : G4UserEventAction(), fHCID(-1){}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

G4RadiacodeEventAction::~G4RadiacodeEventAction(){}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

G4RadiacodeHitsCollection * G4RadiacodeEventAction::GetHitsCollection(G4int hcID, const G4Event* event) const
{
  auto hitsCollection = static_cast<G4RadiacodeHitsCollection*>(event->GetHCofThisEvent()->GetHC(hcID));

  return hitsCollection;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/


void G4RadiacodeEventAction::BeginOfEventAction(const G4Event* event)
{
  return ;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/

void G4RadiacodeEventAction::EndOfEventAction(const G4Event* event)
{
  // Check for Hit Collection ID
  if(fHCID == -1)
  {
    fHCID = G4SDManager::GetSDMpointer()->GetCollectionID("RadiacodeHitsCollection");
  }

  // Retrieve Hit Collection of this Event
  auto hit_collection_of_this_event = GetHitsCollection(fHCID, event);

  const long hit_collection_size = (long) hit_collection_of_this_event->GetSize();

  if(hit_collection_size == 0) return ;

  double edep = 0.0;

  for (long i = 0; i < hit_collection_size; i++)
  {
    edep += (*hit_collection_of_this_event)[i]->GetEdep();
  }

 
  auto fAnalysisManager = G4AnalysisManager::Instance();
  fAnalysisManager->FillNtupleDColumn(0,0,edep);
  fAnalysisManager->AddNtupleRow(0);
  return ;
}
