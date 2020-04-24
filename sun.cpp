#include "sun.h"

SuN::SuN()
{    
}

SuN::SuN(const SuN& obj):SuN()
{
    setValue(0,obj.getValue(0));
    setValue(1,obj.getValue(1));
    setValue(2,obj.getValue(2));
    setValue(3,obj.getValue(3));
}

SuN::~SuN()
{
    //qDebug() << "desctruct";
    this->values.clear();
}

SuN &SuN::operator*=(const SuN& rhs)
{

    double value0=getValue(0)*rhs.getValue(0)-getValue(1)*rhs.getValue(1)-getValue(2)*rhs.getValue(2)-getValue(3)*rhs.getValue(3);
    double value1=getValue(0)*rhs.getValue(1)+getValue(1)*rhs.getValue(0)+getValue(3)*rhs.getValue(2)-getValue(2)*rhs.getValue(3);
    double value2=getValue(0)*rhs.getValue(2)+getValue(2)*rhs.getValue(0)+getValue(1)*rhs.getValue(3)-getValue(3)*rhs.getValue(1);
    double value3=getValue(0)*rhs.getValue(3)+getValue(3)*rhs.getValue(0)+getValue(2)*rhs.getValue(1)-getValue(1)*rhs.getValue(2);

    setValue(0,value0);
    setValue(1,value1);
    setValue(2,value2);
    setValue(3,value3);

    return *this;
}

SuN operator*(const SuN &lhs,const SuN &rhs)
{
    SuN temp(lhs) ;
    temp  *= rhs;
    return  temp;
}


SuN& SuN::operator+=(const SuN& rhs)
{
    setValue(0,getValue(0)+rhs.getValue(0));
    setValue(1,getValue(1)+rhs.getValue(1));
    setValue(2,getValue(2)+rhs.getValue(2));
    setValue(3,getValue(3)+rhs.getValue(3));
    return *this;
}

SuN operator+(const SuN &lhs, const SuN &rhs)
{
    SuN temp=SuN(lhs) ;
    temp += rhs;
    return  temp;
}

SuN& SuN::operator-=(const SuN& rhs)
{
    setValue(0,getValue(0)-rhs.getValue(0));
    setValue(1,getValue(1)-rhs.getValue(1));
    setValue(2,getValue(2)-rhs.getValue(2));
    setValue(3,getValue(3)-rhs.getValue(3));
    return *this;
}

SuN operator-(const SuN &lhs, const SuN &rhs)
{
    SuN temp(lhs) ;
    temp -= rhs;
    return  temp;
}

const double &SuN::getValue(int index) const
{
    return values[index];
}

double &SuN::setValue(int index, const double &value)
{
    values[index]=value;
    return values[index];

}

SuN SuN::dagger(SuN& suN)
{
    SuN result=SuN() ;
    result.setValue(0,suN.getValue(0));
    result.setValue(1,-suN.getValue(1));
    result.setValue(2,-suN.getValue(2));
    result.setValue(3,-suN.getValue(3));

    return result;
}

double SuN::trace(SuN &suN)
{
    return 2*suN.getValue(0);
}

double SuN::determinant(SuN &suN)
{
    return suN.getValue(0)*suN.getValue(0)+suN.getValue(1)*suN.getValue(1)+suN.getValue(2)*suN.getValue(2)+suN.getValue(3)*suN.getValue(3);
}
