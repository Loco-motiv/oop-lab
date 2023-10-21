#include "point.h"

#include <cmath>

Point::Point(double x, double y) : _x(x), _y(y) {}

bool Point::operator ==(const Point& other) const{
    if (_x == other._x and _y == other._y){
        return true;
    }
    return false;
}

std::ostream& operator <<(std::ostream& os, const Point& other){
    os << "x: " << other._x << ", y:" << other._y << std::endl;
    return os;
}
std::istream& operator >>(std::istream& os, Point& other){
    os >> other._x >> other._y;
    return os;
}

double Point::dist(const Point &other) const{
    double xx = this->_x - other._x;
    double yy = this->_y - other._y;
    return std::sqrt(xx * xx + yy * yy);
}

Point::~Point() noexcept
{
    _x = 0;
    _y = 0;
}
