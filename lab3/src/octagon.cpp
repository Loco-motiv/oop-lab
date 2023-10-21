#include "octagon.h"
#include <cmath>

Octagon::Octagon() : _cords(8){};

Octagon::Octagon(std::vector<Point> cords) : _cords(cords){};


Octagon& Octagon::operator =(const Octagon& other){
    _cords = other._cords;
    return *this;
}

Octagon& Octagon::operator =(Octagon&& other){
    _cords = other._cords;
    other._cords.clear();
    return *this;
}

bool Octagon::operator ==(const Octagon &other) const
{
    for (int i = 0; i < 8; i++){
        if (_cords[i]._x != other._cords[i]._x and _cords[i]._y != other._cords[i]._y){
            return false;
        }
    }
    return true;
}

void Octagon::Print_cords(std::ostream& os){
    for (int i = 0; i < 8; i++){
        os << "Octagon vertex " << i+1 << ": x = " << _cords[i]._x << ", y = "<< _cords[i]._y << std::endl;
    }
}

void Octagon::Read_cords(std::istream& os){
    for (int i = 0; i < 8; i++){
        os >> _cords[i]._x >> _cords[i]._y;
    }
}

double Octagon::area() const{
    double a = _cords[0].dist(_cords[1]);
    return 2 * a * a * (1 + std::sqrt(2));
}

Point Octagon::centre() const{
    double x0 = 0;
    double y0 = 0;
    for (int i = 0; i < 8; i++){
        x0 += _cords[i]._x;
        y0 += _cords[i]._y;
    }
    return Point(x0, y0);
}

Octagon::~Octagon() noexcept {}