#include "latticesubset.h"

LatticeSubset::LatticeSubset(int from, int to, int width, int height) {
        this->setFrom(from);
        setTo(to);
        setWidth(width);
        setHeight(height);
}

int LatticeSubset::getFrom() {
    return this->from;
}

void LatticeSubset::setFrom(int from) {
    this->from = from;
}

int LatticeSubset::getTo() {
    return this->to;
}

void LatticeSubset::setTo(int to) {
    this->to = to;
}

int LatticeSubset::getHeight() {
    return this->height;
}

void LatticeSubset::setHeight(int height) {
    this->height = height;
}

int LatticeSubset::getWidth() {
    return this->width;
}

void LatticeSubset::setWidth(int width) {
    this->width = width;
}


