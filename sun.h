#ifndef SUN_H
#define SUN_H


#include <QSharedPointer>
#include <QVector>
#include <QDebug>

class SuN
{
public:
    SuN();
    SuN(const SuN &obj);
    ~SuN();
    SuN& operator+=(const SuN& rhs);
    SuN& operator-=(const SuN& rhs);
    SuN& operator*=(const SuN& rhs);

    friend SuN operator*(const SuN&, const SuN&);
    friend SuN operator+(const SuN&,const SuN&);
    friend SuN operator-(const SuN&,const SuN&);

    const double& getValue(int index) const;
    double& setValue(int index,const double& value);

    static SuN dagger(SuN& suN);
    static double trace(SuN& suN) ;
    static double determinant(SuN& suN) ;



private :
    QVector<double> values={0.0,0.0,0.0,0.0};

};

#endif // SUN_H
