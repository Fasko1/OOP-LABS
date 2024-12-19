#ifndef FIGURE_H
#define FIGURE_H

class Figure {
public:
    virtual double area() const = 0; // Чисто виртуальная функция для вычисления площади
    virtual ~Figure() = default;
};

#endif // FIGURE_H
