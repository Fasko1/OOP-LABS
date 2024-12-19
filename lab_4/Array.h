#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <memory>
#include <iostream>
#include "Figure.h"

template <class T>
class Array {
private:
    std::vector<std::shared_ptr<T>> figures;

public:
    void addFigure(const std::shared_ptr<T>& figure) {
        figures.push_back(figure);
    }

    double totalArea() const {
        double total = 0.0;
        for (const auto& figure : figures) {
            total += figure->area();
        }
        return total;
    }

    void printFigures() const {
        for (const auto& figure : figures) {
            std::cout << "Figure area: " << figure->area() << std::endl;
        }
    }
};

#endif // ARRAY_H
