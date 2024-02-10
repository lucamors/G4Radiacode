#ifndef G4Radiacode_RUN_ACTION_H
#define G4Radiacode_RUN_ACTION_H 1

#include "Analysis.hh"
#include "G4UserRunAction.hh"

class G4Run;


class G4RadiacodeRunAction : public G4UserRunAction
{
  public:

    G4RadiacodeRunAction();
    virtual ~G4RadiacodeRunAction();

    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);

  private:

    G4AnalysisManager* fAnalysisManager;
};

#endif
