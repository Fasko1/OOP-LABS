#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"
#include <cmath>

class Rhombus : public Figure {
private:
    double diagonal1;
    double diagonal2;

public:
    Rhombus(double diagonal1, double diagonal2) : diagonal1(diagonal1), diagonal2(diagonal2) {}

    double area() const override {
        return (diagonal1 * diagonal2) / 2.0;
    }
};

#endif // RHOMBUS_H
