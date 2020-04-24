#include "staples.h"

Staples::Staples()
{
}

SuN Staples::staples(Lattice* lattice,int id, int mu){
    SuN result;
    for (int nu = 0; nu < 4; nu++) {
        if (nu == mu) {
            continue;
        }
        result+=stapleForward(lattice,id, mu, nu);
        result+=stapleBackward(lattice,id, mu, nu);
    }
    return result;
}


SuN Staples::stapleForward(Lattice* lattice,int id, int mu, int nu){

    int a = lattice->getIdOfNeighbor(id, mu, 1);
    int b = lattice->getIdOfNeighbor(id, nu, 1);

    SuN v1(*(lattice->getSiteLink(a,nu)));
    SuN v2(*(lattice->getSiteLink(b, mu)));
    SuN v3(*(lattice->getSiteLink(id, nu)));

    SuN result=(v1*SuN::dagger(v2))*SuN::dagger(v3);
    return result;
}

SuN Staples::stapleBackward(Lattice* lattice,int id, int mu, int nu){
    int usedId = id;
    usedId=lattice->getIdOfNeighbor(usedId, nu, -1);
    int a=lattice->getIdOfNeighbor(usedId, mu, 1);

    SuN v1(*(lattice->getSiteLink(a,nu)));
    SuN v2(*(lattice->getSiteLink(usedId, mu)));
    SuN v3(*(lattice->getSiteLink(usedId, nu)));

    SuN result=(SuN::dagger(v1)*SuN::dagger(v2))*v3;
    return result;
}


