#pragma once
#include "Figure.h"
#include <cmath>

class Hexagon : public Figure {
public:
    Hexagon(double side = 0) : side(side) {}

    void calculateGeometricCenter() const override {
        std::cout << "Геометрический центр правильного шестиугольника совпадает с центром описанной окружности.\n";
    }

    double calculateArea() const override {
        return (3 * sqrt(3) * side * side) / 2;
    }

    void printInfo() const override {
        std::cout << "Шестиугольник с длиной стороны " << side << "\n";
    }

    void input(std::istream& is) override {
        is >> side;
    }

    void output(std::ostream& os) const override {
        os << "Шестиугольник с длиной стороны " << side << "\n";
    }

private:
    double side;
};

std::ostream& operator<<(std::ostream& os, const Hexagon& hexagon);
std::istream& operator>>(std::istream& is, Hexagon& hexagon);
