#include "random.h"

Random::Random()
{
}

double Random::ranlxd() {

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    double result=dist(mt);
    return result;
}

double Random::randx(double low) {
    return low + (1 - low) * Random::ranlxd();
}
