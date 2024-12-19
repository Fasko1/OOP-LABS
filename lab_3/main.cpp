#include "Rombe.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    std::vector<std::shared_ptr<Figure>> figures;
    int choice;
    double side, angle;

    while (true) {
        std::cout << "Choose an option:\n";
        std::cout << "1. Add Rombe\n";
        std::cout << "2. Add Pentagon\n";
        std::cout << "3. Add Hexagon\n";
        std::cout << "4. Remove Figure by Index\n";
        std::cout << "5. Print All Figures\n";
        std::cout << "6. Calculate Total Area\n";
        std::cout << "7. Exit\n";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter side and angle for Rombe: ";
            std::cin >> side >> angle;
            figures.push_back(std::make_shared<Rombe>(side, angle));
        } else if (choice == 2) {
            std::cout << "Enter side for Pentagon: ";
            std::cin >> side;
            figures.push_back(std::make_shared<Pentagon>(side));
        } else if (choice == 3) {
            std::cout << "Enter side for Hexagon: ";
            std::cin >> side;
            figures.push_back(std::make_shared<Hexagon>(side));
        } else if (choice == 4) {
            size_t index;
            std::cout << "Enter index to remove: ";
            std::cin >> index;
            Figure::removeFigure(figures, index);
        } else if (choice == 5) {
            for (const auto& figure : figures) {
                figure->printInfo();
                figure->calculateGeometricCenter();
                std::cout << "Area: " << figure->calculateArea() << "\n";
            }
        } else if (choice == 6) {
            std::cout << "Total Area: " << Figure::totalArea(figures) << "\n";
        } else if (choice == 7) {
            break;
        } else {
            std::cout << "Invalid choice\n";
        }
    }

    return 0;
}
