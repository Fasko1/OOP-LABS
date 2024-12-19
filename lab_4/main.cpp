#include "Array.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Hexagon.h"

int main() {
    Array<Figure> figureArray;

    // Добавление фигур в массив
    figureArray.addFigure(std::make_shared<Rhombus>(5, 4));
    figureArray.addFigure(std::make_shared<Pentagon>(5));
    figureArray.addFigure(std::make_shared<Hexagon>(5));

    // Вывод площадей всех фигур
    figureArray.printFigures();

    // Вывод общей площади всех фигур
    std::cout << "Total area: " << figureArray.totalArea() << std::endl;

    return 0;
}
