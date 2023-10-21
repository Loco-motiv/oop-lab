#include "pentagon.h"
#define _USE_MATH_DEFINES
#include <cmath>

Pentagon::Pentagon() : _cords(5){};

Pentagon::Pentagon(std::vector<Point> cords) : _cords(cords){};


Pentagon& Pentagon::operator =(const Pentagon& other){
    _cords = other._cords;
    return *this;
}

Pentagon& Pentagon::operator =(Pentagon&& other){
    _cords = other._cords;
    other._cords.clear();
    return *this;
}

bool Pentagon::operator ==(const Pentagon &other) const
{
    for (int i = 0; i < 5; i++){
        if (_cords[i]._x != other._cords[i]._x and _cords[i]._y != other._cords[i]._y){
            return false;
        }
    }
    return true;
}

void Pentagon::Print_cords(std::ostream& os){
    for (int i = 0; i < 5; i++){
        os << "Pentagon vertex " << i+1 << ": x = " << _cords[i]._x << ", y = "<< _cords[i]._y << std::endl;
    }
}

void Pentagon::Read_cords(std::istream& os){
    for (int i = 0; i < 5; i++){
        os >> _cords[i]._x >> _cords[i]._y;
    }
}

double Pentagon::area() const{
    double a = _cords[0].dist(_cords[1]);
    return (5 * a * a)/(4 * std::tan(M_PI/5));
}

Point Pentagon::centre() const{
    double x0 = 0;
    double y0 = 0;
    for (int i = 0; i < 5; i++){
        x0 += _cords[i]._x;
        y0 += _cords[i]._y;
    }
    return Point(x0, y0);
}

Pentagon::~Pentagon() noexcept {}