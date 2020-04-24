#include "wilson.h"

Wilson::Wilson()
{

}

double Wilson::average(Lattice* lattice,int height, int width) {
    LatticeSubset latticeSubset(0,lattice->hypervolume, width, height);
    double total_sum=wilsonSubset(lattice,latticeSubset);
    // two for scaling
    double result = total_sum / (2 * 6 * lattice->hypervolume);
    return result;
}


double Wilson::wilsonSubset(Lattice* lattice,LatticeSubset latticeSubset) {
    double sum = 0;

    int from = latticeSubset.getFrom();
    int to = latticeSubset.getTo();

    int width = latticeSubset.getWidth();
    int height = latticeSubset.getHeight();

    for (int id = from; id < to; id++) {
        for (int mu = 1; mu < 4; mu++) {
            for (int nu = 0; nu < mu; nu++) {
                sum += wilsonLoop(lattice,id, mu, nu, height, width);
            }
        }
    }
    return sum;
}


double Wilson::wilsonLoop(Lattice* lattice,int id, int mu, int nu, int height,
        int width) {

    SuN fw(*(lattice->getSiteLink(id, mu)));
    SuN bk(*(lattice->getSiteLink(id, nu)));

    int pos = id;
    for (int ndx = 1; ndx < height; ndx++) {
        pos = lattice->getIdOfNeighbor(pos, mu, 1);
        fw*=(*(lattice->getSiteLink(pos, mu)));
    }

    pos = lattice->getIdOfNeighbor(pos, mu, 1);
    fw*=(*(lattice->getSiteLink(pos, nu)));
    for (int ndx = 1; ndx < width; ndx++) {
        pos = lattice->getIdOfNeighbor(pos, nu, 1);
        fw*=(*(lattice->getSiteLink(pos, nu)));
    }

    pos = id;
    for (int ndx = 1; ndx < width; ndx++) {
        pos = lattice->getIdOfNeighbor(pos, nu, 1);
        bk*=(*lattice->getSiteLink(pos, nu));
    }

    pos = lattice->getIdOfNeighbor(pos, nu, 1);
    bk*=(*(lattice->getSiteLink(pos, mu)));
    for (int ndx = 1; ndx < height; ndx++) {
        pos = lattice->getIdOfNeighbor(pos, mu, 1);
        bk*=(*(lattice->getSiteLink(pos, mu)));
    }

    //todo
    SuN resultFoo;
    resultFoo=fw*(SuN::dagger(bk));
    double result=SuN::trace(resultFoo);

    return result;

}




