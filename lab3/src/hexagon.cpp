#include "hexagon.h"
#include <cmath>

Hexagon::Hexagon() : _cords(6){};

Hexagon::Hexagon(std::vector<Point> cords) : _cords(cords){};


Hexagon& Hexagon::operator =(const Hexagon& other){
    _cords = other._cords;
    return *this;
}

Hexagon& Hexagon::operator =(Hexagon&& other){
    _cords = other._cords;
    other._cords.clear();
    return *this;
}

bool Hexagon::operator ==(const Hexagon &other) const
{
    for (int i = 0; i < 6; i++){
        if (_cords[i]._x != other._cords[i]._x and _cords[i]._y != other._cords[i]._y){
            return false;
        }
    }
    return true;
}

void Hexagon::Print_cords(std::ostream& os){
    for (int i = 0; i < 6; i++){
        os << "Hexagon vertex " << i+1 << ": x = " << _cords[i]._x << ", y = "<< _cords[i]._y << std::endl;
    }
}

void Hexagon::Read_cords(std::istream& os){
    for (int i = 0; i < 6; i++){
        os >> _cords[i]._x >> _cords[i]._y;
    }
}

double Hexagon::area() const{
    double a = _cords[0].dist(_cords[1]);
    return (3 * std::sqrt(3) * a * a)/2;
}

Point Hexagon::centre() const{
    double x0 = 0;
    double y0 = 0;
    for (int i = 0; i < 6; i++){
        x0 += _cords[i]._x;
        y0 += _cords[i]._y;
    }
    return Point(x0, y0);
}

Hexagon::~Hexagon() noexcept {}