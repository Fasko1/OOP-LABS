#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include <cmath>

class Pentagon : public Figure {
private:
    double side;

public:
    Pentagon(double side) : side(side) {}

    double area() const override {
        return (1.0 / 4.0) * std::sqrt(5 * (5 + 2 * std::sqrt(5))) * side * side;
    }
};

#endif // PENTAGON_H
