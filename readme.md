# TEPC Detector

A Geant4 implamentation of a Tissue Equivalent Proportional Counter (TEPC).

Based on : The   microdosimetric   extension   in   TOPAS:   Development   and comparison with publisheddata Zhu et al. 2019

<img width="500" src="docs/tepc.svg" alt>
<em>Visualization of 50 events from a <sup>12</sup>C beam at 300 MeV/u. Spherical TEPC Geometry.</em>

<img width="500" src="docs/tepccy.svg" alt>
<em>Mini TEPC with Cylindrical Geometry.</em>

## Installation

Clone the repository using :
```bash
git clone https://github.com/lucamors/G4Radiacode.git
```

Now create a build directory inside the ```G4Radiacode``` directory:

```bash
mkdir build && cd build
```

Launch cmake with the geometry of choice :

1. For spherical geometry:
```bash
cmake -DSPHERICAL_GEOMETRY=ON ..
```
2. For cylindrical geometry:
```bash
cmake ..
```

Finally you can build the application (using <N> core):
```bash
make -j<N>
```

## Usage

The ```G4RadiacodePrimaryGenerator``` is built around the use of ```G4GeneralParticleSource``` (i.e. GPS)
and example for a <sup>12</sup>C beam with 300 MeV/u can be found in:
```bash
macro/examples/C12.mac
```