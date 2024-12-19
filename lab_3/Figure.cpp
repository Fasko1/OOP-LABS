#include "Figure.h"
#include "Rombe.h"
#include "Pentagon.h"
#include "Hexagon.h"

std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    figure.output(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& figure) {
    figure.input(is);
    return is;
}

void Figure::removeFigure(std::vector<std::shared_ptr<Figure>>& figures, size_t index) {
    if (index < figures.size()) {
        figures.erase(figures.begin() + index);
    } else {
        std::cerr << "Invalid index\n";
    }
}

double Figure::totalArea(const std::vector<std::shared_ptr<Figure>>& figures) {
    double total = 0.0;
    for (const auto& figure : figures) {
        total += figure->calculateArea();
    }
    return total;
}
