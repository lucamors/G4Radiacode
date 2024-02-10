# Radiacode Digital Twin

## Introduction

A Geant4 implamentation of the scintillator crystal inside the Radiacode detector.

### Prerequisites

> [!WARNING]  
> In order to correctly compile this application you need both the Geant4 libraries (v. 4.11.2) and the ROOT libraries already installed on your system. 

A few lines on installation

### Compile the application

Clone the repository using :
```bash
git clone https://github.com/lucamors/G4Radiacode.git
```

Now create a build directory inside the ```G4Radiacode``` directory:

```bash
mkdir build && cd build
```

Launch CMake :
```bash
cmake ..
```

Finally you can build the application (using <N> core):
```bash
make -j<N>
```

### Usage

The ```G4RadiacodePrimaryGenerator``` is built around the use of ```G4GeneralParticleSource``` (i.e. GPS)
and example for a <sup>60</sup>Co source you can use:
```bash
macro/examples/co60.mac
```