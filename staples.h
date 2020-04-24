#ifndef STAPLES_H
#define STAPLES_H

#include "sun.h"
#include "lattice.h"

class Staples
{
    public:
            static SuN staples(Lattice* lattice,int id, int mu);

    private:
        static SuN stapleForward(Lattice* lattice,int id, int mu, int nu);
        static SuN stapleBackward(Lattice* lattice,int id, int mu, int nu);

private:
    Staples();
};

#endif // STAPLES_H
