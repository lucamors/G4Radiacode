#include "G4RadiacodeRunAction.hh"
#include "Analysis.hh"
#include "G4Run.hh"

G4RadiacodeRunAction::G4RadiacodeRunAction() : G4UserRunAction()
{
  fAnalysisManager = G4AnalysisManager::Instance();

  fAnalysisManager->SetVerboseLevel(1);

  fAnalysisManager->CreateNtuple("ht","Radiacode Simulation");
  fAnalysisManager->CreateNtupleDColumn("edep");
  fAnalysisManager->FinishNtuple();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

G4RadiacodeRunAction::~G4RadiacodeRunAction(){}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void G4RadiacodeRunAction::BeginOfRunAction(const G4Run * run)
{
  fAnalysisManager->OpenFile();
  return ;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void G4RadiacodeRunAction::EndOfRunAction(const G4Run * run)
{

  fAnalysisManager->Write();
  fAnalysisManager->CloseFile();
  return ;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
