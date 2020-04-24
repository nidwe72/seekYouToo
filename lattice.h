#ifndef LATTICE_H
#define LATTICE_H

#include <QObject>
#include "latticesite.h"
#include "latticeneighbor.h"
#include "sun.h"

class Lattice : public QObject
{
    Q_OBJECT
public:    
    explicit Lattice(int dim=0,double bt=0.0,QObject *parent = nullptr);
    int hypervolume = 0;
    double beta = 0;
    SuN* getSiteLink(int n, int d);
    void setSiteLink(int n, int d, SuN* siteLink);
    int getIdFromOffset(int id, int to, int x0, int y0, int z0);
    int getIdFromPosition(int t, int x, int y, int z);
    void calculate_neighbors();
    int getIdOfNeighbor(int id, int mu, int dist);
    void reset(double t, double x, double y, double z);

private:

    int length = 0;
    int area = 0;
    int volume = 0;

    QVector<LatticeSite*> sites{};
    QVector<LatticeNeighbor*> neighbors{};

signals:

};

#endif // LATTICE_H
