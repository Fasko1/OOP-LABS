#pragma once
#include "Figure.h"
#include <cmath>

class Rombe : public Figure {
public:
    Rombe(double side = 0, double angle = 0) : side(side), angle(angle) {}

    void calculateGeometricCenter() const override {
        std::cout << "Геометрический центр ромба совпадает с пересечением диагоналей.\n";
    }

    double calculateArea() const override {
        return side * side * sin(angle);
    }

    void printInfo() const override {
        std::cout << "Ромб с длиной стороны " << side << " и углом " << angle << " радиан.\n";
    }

    void input(std::istream& is) override {
        is >> side >> angle;
    }

    void output(std::ostream& os) const override {
        os << "Ромб с длиной стороны " << side << " и углом " << angle << " радиан.\n";
    }

private:
    double side;
    double angle;
};

std::ostream& operator<<(std::ostream& os, const Rombe& rombe);
std::istream& operator>>(std::istream& is, Rombe& rombe);
