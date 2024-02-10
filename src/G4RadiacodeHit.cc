#include "G4RadiacodeHit.hh"

G4ThreadLocal G4Allocator<G4RadiacodeHit>* G4RadiacodeHitAllocator = 0;

G4RadiacodeHit::G4RadiacodeHit() : G4VHit()
{
  fEdep = 0.0;
}

G4RadiacodeHit::~G4RadiacodeHit(){}

G4RadiacodeHit::G4RadiacodeHit(const G4RadiacodeHit& right) : G4VHit()
{
	fEdep = right.fEdep;
}

const G4RadiacodeHit& G4RadiacodeHit::operator=(const G4RadiacodeHit& right)
{
	fEdep = right.fEdep;
	return *this;
}

G4int G4RadiacodeHit::operator==(const G4RadiacodeHit& right) const
{
	return (this == &right ) ? 1 : 0;
}
