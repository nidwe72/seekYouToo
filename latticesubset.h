#ifndef LATTICESUBSET_H
#define LATTICESUBSET_H

class LatticeSubset
{
public:
    LatticeSubset(int from=0, int to=0, int width=0, int height=0);

    int getFrom();
    void setFrom(int from);

    int getTo();
    void setTo(int to);

    int getWidth();
    void setWidth(int width);

    int getHeight();
    void setHeight(int height);


private:
        int from;
        int to;
        int width;
        int height;

};

#endif // LATTICESUBSET_H
