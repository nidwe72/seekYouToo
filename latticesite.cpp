#include "latticesite.h"

LatticeSite::LatticeSite(QObject *parent) : QObject(parent)
{
    at=QSharedPointer<SuN>(new SuN());
    ax=QSharedPointer<SuN>(new SuN());
    ay=QSharedPointer<SuN>(new SuN());
    az=QSharedPointer<SuN>(new SuN());
}

LatticeSite::~LatticeSite()
{

}
