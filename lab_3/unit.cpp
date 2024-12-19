#include <gtest/gtest.h>
#include "Rombe.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include <sstream>

TEST(FigureTest, RombeArea) {
    Rombe rombe(5, M_PI / 3);
    ASSERT_NEAR(rombe.calculateArea(), 21.6506, 1e-4);
}

TEST(FigureTest, PentagonArea) {
    Pentagon pentagon(5);
    ASSERT_NEAR(pentagon.calculateArea(), 43.0119, 1e-4);
}

TEST(FigureTest, HexagonArea) {
    Hexagon hexagon(5);
    ASSERT_NEAR(hexagon.calculateArea(), 64.9519, 1e-4);
}

TEST(FigureTest, RombeIO) {
    Rombe rombe;
    std::istringstream iss("5 1.0472"); // 1.0472 радиан ≈ 60 градусов
    iss >> rombe;
    ASSERT_NEAR(rombe.calculateArea(), 21.6506, 1e-4);

    std::ostringstream oss;
    oss << rombe;
    ASSERT_EQ(oss.str(), "Ромб с длиной стороны 5 и углом 1.0472 радиан.\n");
}

TEST(FigureTest, PentagonIO) {
    Pentagon pentagon;
    std::istringstream iss("5");
    iss >> pentagon;
    ASSERT_NEAR(pentagon.calculateArea(), 43.0119, 1e-4);

    std::ostringstream oss;
    oss << pentagon;
    ASSERT_EQ(oss.str(), "Пятиугольник с длиной стороны 5\n");
}

TEST(FigureTest, HexagonIO) {
    Hexagon hexagon;
    std::istringstream iss("5");
    iss >> hexagon;
    ASSERT_NEAR(hexagon.calculateArea(), 64.9519, 1e-4);

    std::ostringstream oss;
    oss << hexagon;
    ASSERT_EQ(oss.str(), "Шестиугольник с длиной стороны 5\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
