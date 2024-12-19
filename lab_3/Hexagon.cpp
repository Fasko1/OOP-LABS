#include "Hexagon.h"

std::ostream& operator<<(std::ostream& os, const Hexagon& hexagon) {
    hexagon.output(os);
    return os;
}

std::istream& operator>>(std::istream& is, Hexagon& hexagon) {
    hexagon.input(is);
    return is;
}
