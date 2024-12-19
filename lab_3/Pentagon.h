#pragma once
#include "Figure.h"
#include <cmath>

class Pentagon : public Figure {
public:
    Pentagon(double side = 0) : side(side) {}

    void calculateGeometricCenter() const override {
        std::cout << "Геометрический центр правильного пятиугольника совпадает с центром описанной окружности.\n";
    }

    double calculateArea() const override {
        return (5 * side * side) / (4 * tan(M_PI / 5));
    }

    void printInfo() const override {
        std::cout << "Пятиугольник с длиной стороны " << side << "\n";
    }

    void input(std::istream& is) override {
        is >> side;
    }

    void output(std::ostream& os) const override {
        os << "Пятиугольник с длиной стороны " << side << "\n";
    }

private:
    double side;
};

std::ostream& operator<<(std::ostream& os, const Pentagon& pentagon);
std::istream& operator>>(std::istream& is, Pentagon& pentagon);
