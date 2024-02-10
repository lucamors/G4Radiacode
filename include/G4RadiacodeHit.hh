#ifndef G4Radiacode_HIT_H
#define G4Radiacode_HIT_H 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"

class G4RadiacodeHit : public G4VHit
{
  public:

    // Constructors
    G4RadiacodeHit();
    G4RadiacodeHit(const G4RadiacodeHit&);
    // Destructor
    ~G4RadiacodeHit();

    // Operators
    const G4RadiacodeHit& operator=(const G4RadiacodeHit&);
    G4int operator==(const G4RadiacodeHit&) const;

    inline void * operator new(size_t);
    inline void   operator delete(void*);

    // User Defined Hit Interface

    void SetEdep(G4double edep){ fEdep = edep; };
    G4double GetEdep(){ return fEdep; };

  private:

    G4double fEdep;
};

using G4RadiacodeHitsCollection = G4THitsCollection<G4RadiacodeHit>;
extern G4ThreadLocal G4Allocator<G4RadiacodeHit>* G4RadiacodeHitAllocator;

inline void* G4RadiacodeHit::operator new(size_t)
{
  if(!G4RadiacodeHitAllocator) G4RadiacodeHitAllocator = new G4Allocator<G4RadiacodeHit>;

  void * hit;
  hit = (void*) G4RadiacodeHitAllocator->MallocSingle();

  return hit;
}

inline void G4RadiacodeHit::operator delete(void *hit)
{
  if(!G4RadiacodeHitAllocator) G4RadiacodeHitAllocator = new G4Allocator<G4RadiacodeHit>;

  G4RadiacodeHitAllocator->FreeSingle((G4RadiacodeHit*)hit);

  return ;
}

#endif
