#include "figure.h"
#include "hexagon.h"
#include "octagon.h"
#include "pentagon.h"
#include <vector>
#include <math.h>
#include <iostream>

int main(){
    Figure* o1 = new Octagon;
    Figure* o2 = o1;    
    std::cin >> *o1;
    std::cout << *o1;
    std::cout << o1->centre() << o1->area();
    std::cout << (*dynamic_cast<Octagon*>(o1) == *dynamic_cast<Octagon*>(o2));

    std::vector<Figure*> figures;
    Figure* hexagon = new Hexagon;
    Figure* octagon = new Octagon;
    Figure* pentagon = new Pentagon;
    std::cout << "Enter coordinates for hexagon:" << std::endl;
    std::cin >> *hexagon;
    std::cout << "Enter coordinates for octagon:" << std::endl;
    std::cin >> *octagon;
    std::cout << "Enter coordinates for pentagon:" << std::endl;
    std::cin >> *pentagon;
    std::cout << std::endl;
    std::cout << "Repeat of coordinates for hexagon" << *hexagon << std::endl;
    std::cout << "Repeat of coordinates for octagon" << *octagon << std::endl;
    std::cout << "Repeat of coordinates for pentagon" << *pentagon << std::endl;
    figures.push_back(hexagon);
    figures.push_back(octagon);
    figures.push_back(pentagon);

    for (const auto& figure : figures) {
        std::cout << "CenterX is: " << figure->centre() << std::endl;
        std::cout << "Area: " << figure->operator double() << std::endl;
    }

    double Area = 0.0;
    for (const auto& figure : figures) {
        Area += figure->operator double();
    }
    std::cout << "Total Area: " << Area << std::endl;

    int index;

    std::cout << "Enter the number of index to delete" << std::endl;
    std::cin >> index;
    if (index >= 0 && index < figures.size()) {
        delete figures[index];
        figures.erase(figures.begin() + index);
    }
    return 0;
}