#include "Pentagon.h"

std::ostream& operator<<(std::ostream& os, const Pentagon& pentagon) {
    pentagon.output(os);
    return os;
}

std::istream& operator>>(std::istream& is, Pentagon& pentagon) {
    pentagon.input(is);
    return is;
}
