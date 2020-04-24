#include "latticesite.h"

LatticeSite::LatticeSite(QObject *parent) : QObject(parent)
{
    at=new SuN();
    ax=new SuN();
    ay=new SuN();
    az=new SuN();
}
