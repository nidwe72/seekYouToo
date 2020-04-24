#ifndef WILSON_H
#define WILSON_H

#include "lattice.h"
#include "latticesubset.h"

class Wilson
{
public:    
    static double average(Lattice* lattice, int height, int width);

private:
    Wilson();
    static double wilsonSubset(Lattice* lattice,LatticeSubset latticeSubset);
    static double wilsonLoop(Lattice* lattice, int id, int mu, int nu, int height, int width);
};

#endif // WILSON_H
