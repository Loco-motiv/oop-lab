#include "figure.h"

Figure::Figure(){};

Figure::Figure(std::vector<Point> cords) : _cords(cords){};

Figure& Figure::operator =(const Figure& other){};

Figure& Figure::operator =(Figure&& other){};

bool Figure::operator ==(const Figure &other) const {};

std::ostream& operator <<(std::ostream &os, Figure& other)
{
    other.Print_cords(os);
    return os;
}

std::ostream& operator >>(std::istream &os, Figure& other)
{   
    other.Read_cords(os);
}

Figure::~Figure() noexcept {}