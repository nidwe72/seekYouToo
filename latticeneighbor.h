#ifndef LATTICENEIGHBOR_H
#define LATTICENEIGHBOR_H

#include <QVector>

class LatticeNeighbor
{
public:
    LatticeNeighbor();
    ~LatticeNeighbor();
    QVector<int> nb{0,0,0,0};
};

#endif // LATTICENEIGHBOR_H
