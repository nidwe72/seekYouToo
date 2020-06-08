#include "lattice.h"


Lattice::Lattice(int dim,double bt,QObject *parent) : QObject(parent)
{
    length=dim;
    area = dim * dim;
    volume = dim * dim * dim;
    hypervolume = dim * dim * dim * dim;
    beta = bt;

    for (int i = 0; i < hypervolume; i++) {
        sites.append(QSharedPointer<LatticeSite>(new LatticeSite()));
        neighbors.append(new LatticeNeighbor());
    }
}

QSharedPointer<SuN> Lattice::getSiteLink(int n, int d) {

    QSharedPointer<SuN> result;
    switch (d) {
    case 0:
        result=sites.at(n)->at;
        break;
    case 1:
        result=sites.at(n)->ax;
        break;
    case 2:
        result=sites.at(n)->ay;
        break;
    case 3:
        result=sites.at(n)->az;
        break;
    }

    return result;
}

void Lattice::setSiteLink(int n, int d, SuN* siteLink) {
    switch (d) {
    case 0:
        sites.at(n)->at=QSharedPointer<SuN>(siteLink);
        break;
    case 1:
        sites.at(n)->ax=QSharedPointer<SuN>(siteLink);
        break;
    case 2:
        sites.at(n)->ay=QSharedPointer<SuN>(siteLink);
        break;
    case 3:
        sites.at(n)->az=QSharedPointer<SuN>(siteLink);
        break;
    }
}

int Lattice::getIdFromOffset(int id, int to, int x0, int y0, int z0) {
    int t;
    int x;
    int y;
    int z;
    t = id / volume;
    id = id % volume;

    z = id / area;
    id = id % area;

    y = id / length;
    x = (id % length);

    x = (x + x0) % length;
    if (x < 0) {
        x = x + length;
    }
    y = (y + y0) % length;

    if (y < 0) {
        y = y + length;
    }

    z = (z + z0) % length;
    if (z < 0) {
        z = z + length;
    }

    t = (t + to) % length;

    if (t < 0) {
        t = t + length;
    }

    int result=this->getIdFromPosition(t, x, y, z);

    return result;
}

int Lattice::getIdFromPosition(int t, int x, int y, int z) {
    int result=x + y * length + z * area + t * volume;
    return result;
}

void Lattice::calculate_neighbors() {
    for (int id = 0; id < hypervolume; id++) {
        neighbors[id]->nb[0]=this->getIdFromOffset(id, 1, 0, 0, 0);
        neighbors[id]->nb[1]=this->getIdFromOffset(id, 0, 1, 0, 0);
        neighbors[id]->nb[2]=this->getIdFromOffset(id, 0, 0, 1, 0);
        neighbors[id]->nb[3]=this->getIdFromOffset(id, 0, 0, 0, 1);
    }
}

int Lattice::getIdOfNeighbor(int id, int mu, int dist) {
    int result = id;
    int usedDist = dist;
    // assuming abs( dist ) < length
    if (usedDist < 0) {
        usedDist += length;
    }
    // FIXXME:check whether index is okay
    while (usedDist > 0) {
        result=this->neighbors[result]->nb[mu];
        usedDist--;
    }
    return result;
}

void Lattice::reset(double t, double x, double y, double z) {


    foreach( QSharedPointer<LatticeSite> site, this->sites ){
        site->at->setValue(0,t);
        site->at->setValue(1,x);
        site->at->setValue(2,y);
        site->at->setValue(3,z);

        site->ax->setValue(0,t);
        site->ax->setValue(1,x);
        site->ax->setValue(2,y);
        site->ax->setValue(3,z);

        site->ay->setValue(0,t);
        site->ay->setValue(1,x);
        site->ay->setValue(2,y);
        site->ay->setValue(3,z);

        site->az->setValue(0,t);
        site->az->setValue(1,x);
        site->az->setValue(2,y);
        site->az->setValue(3,z);

    }

}






