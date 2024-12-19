#include <gtest/gtest.h>
#include "Array.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Hexagon.h"

TEST(FigureTest, RhombusArea) {
    Rhombus rhombus(5, 4);
    ASSERT_NEAR(rhombus.area(), 10.0, 1e-6);
}

TEST(FigureTest, PentagonArea) {
    Pentagon pentagon(5);
    ASSERT_NEAR(pentagon.area(), (1.0 / 4.0) * std::sqrt(5 * (5 + 2 * std::sqrt(5))) * 25, 1e-6);
}

TEST(FigureTest, HexagonArea) {
    Hexagon hexagon(5);
    ASSERT_NEAR(hexagon.area(), (3 * std::sqrt(3) / 2) * 25, 1e-6);
}

TEST(ArrayTest, TotalArea) {
    Array<Figure> figureArray;
    figureArray.addFigure(std::make_shared<Rhombus>(5, 4));
    figureArray.addFigure(std::make_shared<Pentagon>(5));
    figureArray.addFigure(std::make_shared<Hexagon>(5));

    double expectedTotalArea = 10.0 + (1.0 / 4.0) * std::sqrt(5 * (5 + 2 * std::sqrt(5))) * 25 + (3 * std::sqrt(3) / 2) * 25;
    ASSERT_NEAR(figureArray.totalArea(), expectedTotalArea, 1e-6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
