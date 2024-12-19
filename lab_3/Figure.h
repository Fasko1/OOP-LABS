#pragma once
#include <iostream>
#include <vector>
#include <memory>

class Figure {
public:
    virtual ~Figure() = default;
    virtual void calculateGeometricCenter() const = 0;
    virtual double calculateArea() const = 0;
    virtual void printInfo() const = 0;
    virtual void input(std::istream& is) = 0;
    virtual void output(std::ostream& os) const = 0;

    static void removeFigure(std::vector<std::shared_ptr<Figure>>& figures, size_t index);
    static double totalArea(const std::vector<std::shared_ptr<Figure>>& figures);
};

std::ostream& operator<<(std::ostream& os, const Figure& figure);
std::istream& operator>>(std::istream& is, Figure& figure);
