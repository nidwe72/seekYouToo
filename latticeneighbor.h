#ifndef LATTICENEIGHBOR_H
#define LATTICENEIGHBOR_H

#include <QObject>

class LatticeNeighbor
{
public:
    LatticeNeighbor();
    QVector<int> nb{0,0,0,0};
};

#endif // LATTICENEIGHBOR_H
