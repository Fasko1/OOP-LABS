#include "Rombe.h"

std::ostream& operator<<(std::ostream& os, const Rombe& rombe) {
    rombe.output(os);
    return os;
}

std::istream& operator>>(std::istream& is, Rombe& rombe) {
    rombe.input(is);
    return is;
}
