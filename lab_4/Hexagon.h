#ifndef HEXAGON_H
#define HEXAGON_H

#include "Figure.h"
#include <cmath>

class Hexagon : public Figure {
private:
    double side;

public:
    Hexagon(double side) : side(side) {}

    double area() const override {
        return (3 * std::sqrt(3) / 2) * side * side;
    }
};

#endif // HEXAGON_H
