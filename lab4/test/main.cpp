#include "figure.h"
#include "hexagon.h"
#include "octagon.h"
#include "pentagon.h"
#include "array.h"
#include <memory>
#include <math.h>
#include <iostream>

int main(){
    Point<double> O1(0.0, 0.0);
    Point<double> O2(2.0, 0.0);
    Point<double> O3(4.0, 2.0);
    Point<double> O4(4.0, 4.0);
    Point<double> O5(2.0, 6.0);
    Point<double> O6(0.0, 6.0);
    Point<double> O7(-2.0, 4.0);
    Point<double> O8(-2.0, 2.0);

    Point<double> H1(0.0, 0.0);
    Point<double> H2(2.0, 0.0);
    Point<double> H3(3.0, 2.0);
    Point<double> H4(2.0, 4.0);
    Point<double> H5(0.0, 4.0);
    Point<double> H6(-1.0, 2.0);

    Point<double> P1(8.0, 0.0);
    Point<double> P2(12.0, 2.0);
    Point<double> P3(10.0, 6.0);
    Point<double> P4(6.0, 6.0);
    Point<double> P5(4.0, 2.0);


    Array<std::shared_ptr<Figure<double>>> array{
                                    std::make_shared<Hexagon<double>>(H1,H2,H3,H4,H5,H6),
                                    std::make_shared<Octagon<double>>(O1, O2, O3, O4, O5, O6, O7, O8),
                                    std::make_shared<Pentagon<double>>(P1, P2, P3, P4, P5)
                                    };


    for (size_t i = 0; i < array.size() ; ++i) {
        std::shared_ptr<Figure<double>> figure = array[i];
        Point<double> center = figure->centre();
        std::cout << *figure;
        std::cout << "Center: (" << center << ")\n";
        std::cout << "Area: " << figure->operator double() << "\n";
    }

    std::cout << "Total Area: " << array.totalArea() << "\n";

    return 0;
}